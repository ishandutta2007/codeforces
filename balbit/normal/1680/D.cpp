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
ll ps[maxn], n0[maxn], a[maxn];
int n,k; 

ll get(){
    REP1(i,n) {
        ps[i] = ps[i-1] + a[i];
        n0[i] = n0[i-1] + (a[i] == 0);
    }
    ll re = -2;
    REP(i,n+1) FOR(j,i,n+1) {
        int B = n0[j] - n0[i];
        int A = n0[n] - B;

        int btw = ps[j] - ps[i], out = ps[n] - btw;

        int l1 = -A*k + out, r1 = A*k + out;
        int l2 = -B*k - btw, r2 = B*k - btw;

        if (l2 > r1 || r2 < l1) continue;
        bug(i,j);
        bug(l1, r1, l2, r2);

        MX(re, min(r1, r2));
    }
    return re;
}

signed main(){
    ios::sync_with_stdio(0);
    bug(1,2);
    cin>>n>>k;

    REP1(i,n) {
        cin>>a[i];
    }

    ll g1 = get();
    REP1(i,n) a[i] = -a[i];
    ll g2 = get();
    bug(g1, g2);
    int re = max(g1, g2);
    if (re < 0) cout<<-1<<endl;
    else cout<<re+1<<endl;
    // cout<<max(g1, g2)<<endl;

}