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


const int maxn = 2e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll a[maxn], b[maxn];
int n,k;

struct yo{
    ll T,a,b;
    // a - b*T < 0 => T = floor(a/b)+1
    bool operator < (const yo & o) const {
        return T > o.T;
    }
};

bool ok(ll x) {

    priority_queue<yo> pq;
    REP(i,n) {
        pq.push({a[i]/b[i], a[i], b[i]});
    }
    REP(t, k) {
        yo e = pq.top(); pq.pop();
        // is it dead?
        if (e.a - t*e.b < 0) return 0;
        e.a += x;
        pq.push({e.a/e.b, e.a, e.b});
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);

    cin>>n>>k;
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];

    ll l = 0, r = 100000000000000;
    while (l!=r) {
        ll mid = (l+r)/2;
        if (ok(mid)) {
            r = mid;
        }else l = mid+1;
    }
    ll re = l;
    if (re == 100000000000000) re = -1;
    cout<<re<<endl;
}

// 100 3 1 10 5 20 20 100