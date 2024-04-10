#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define int ll
#define f first
#define s second

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)

#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)
#define pb push_back
#define SZ(x) (int)((x).size())

#define ALL(x) (x).begin(), (x).end()

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<" "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do( T && x ) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do( T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif

const int maxn = 3e3+5;

array<vector<int>, 2> go(string A[2]) {
    int n = SZ(A[0]);
    array<vector<int>, 2> re;
    re[0].resize(n);
    re[1].resize(n);
    bool stuff = 0;
    REP(i,n) {

        re[0][i] = ((stuff)?re[0][i-1]+1:0) + (A[1][i]=='*');
        re[1][i] = ((stuff)?re[1][i-1]+1:0) + (A[0][i]=='*');
        if (A[1][i]=='*' || A[0][i]=='*') stuff = 1;
        MN(re[0][i], re[1][i] + 1 - (A[0][i] == '*'));
        MN(re[1][i], re[0][i] + 1 - (A[1][i] == '*'));
        bug(i, re[0][i], re[1][i]);
    }
    bug(re[0][n-1], re[1][n-1]);
    return re;
}

signed main(){
    ios::sync_with_stdio(0);
    bug(1,2);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        string A[2]; cin>>A[0]>>A[1];
        auto g1 = go(A);
        reverse(ALL(A[0]));
        reverse(ALL(A[1]));
        auto g2 = go(A);
        reverse(ALL(g2[0]));
        reverse(ALL(g2[1]));

        reverse(ALL(A[0]));
        reverse(ALL(A[1]));
        int lastitem = -1;
        for (int i = n-1; i>=0; --i) {
            if (A[0][i] == '*' || A[1][i] == '*') {
                lastitem = i; break;
            }
        }
        bug(lastitem);
        int re = min(g2[0][0], g2[1][0]);
        // int re = 2*n;
        REP(b,2) REP(i,n) {
            int ha = g1[b][i] + (i+1<n?g2[b][i+1] : 0);
            if (i+1 < n && i+1 <= lastitem) ++ha;
            bug(b,i,ha);
            MN(re, ha);
        }
        cout<<re<<endl;
    }

}