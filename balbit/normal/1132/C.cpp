#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) for (int i = 0; i<n; ++i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)

#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)


#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT


const int maxn = 5e3+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int num[maxn];
int p1[maxn], p2[maxn];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    bug(1,2);
    int n,q; cin>>n>>q;
    vector<pii> v;
    REP(i,q) {
        int l,r; cin>>l>>r; --l; --r;
        ++num[l]; --num[r+1];
        v.pb({l,r});
    }
    int tot = 0;
    REP(i,n) {
        if (i) {
            num[i] += num[i-1];
        }
        p1[i+1] = p1[i]; p2[i+1] = p2[i]; // p1 and p2 are 1-based
        if (num[i] == 1) ++p1[i+1];
        if (num[i] == 2) ++p2[i+1];
        tot += num[i] > 0;
    }
    bug(tot);
    int re = tot;
    REP(i,q) {
        REP(j,i) {
            pii a = v[i], b = v[j];
            int bad1 = p1[a.s+1] - p1[a.f] + p1[b.s+1] - p1[b.f];
//            bug(p1[a.s+1] - p1[a.f], p1[b.s+1] - p1[b)
            int L = max(a.f, b.f); int R = min(a.s, b.s);
            int bad2 = L<=R?p2[R+1] - p2[L] : 0;
            if (L<=R)assert(p1[R+1] - p1[L] == 0);
            bug(i,j,L,R,bad1,bad2);
            MN(re, bad1 + bad2);
        }
    }
    cout<<tot - re<<endl;


}

// 100 3 1 10 5 20 20 100