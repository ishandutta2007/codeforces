#include <bits/stdc++.h>
using namespace std;

#define int ll

#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i = n-1; i>=0; --i)

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<"- "<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T && x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y){cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT

const int maxn = 1e6+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

int n,m;

int mn[maxn*4]; //, cnt[maxn*4]; // min, number of min
int tg[maxn*4];

void push(int o, int l, int r) {
    if (tg[o]) {
        mn[o] += tg[o];
        if (l!=r) {
            tg[o*2] += tg[o];
            tg[o*2+1] += tg[o];
        }
        tg[o] = 0;
    }
}


void MO(int L, int R, int v, int o=1, int l=0, int r=m-2) {
    push(o,l,r);
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        tg[o] += v;
        push(o,l,r); return;
    }
    int mid = (l+r)/2;
    MO(L,R,v,o*2,l,mid); MO(L,R,v,o*2+1,mid+1,r);
    mn[o] = min(mn[o*2], mn[o*2+1]);
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    bug(1,2);
    cin>>n>>m;
    vector<pair<int, pii> > v;
    REP(i,n) {
        int l,r,w; cin>>l>>r>>w; --l; --r; --r;
        v.pb({w,{l,r}});
    }
    sort(ALL(v));
    ll re = inf;
    int j = 0;
    REP(i, SZ(v)) {
        MO(v[i].s.f, v[i].s.s, 1);
        while (mn[1] != 0) {
            bug("ok", i, j, v[j].f, v[i].f);
            MN(re, v[i].f - v[j].f);
            MO(v[j].s.f, v[j].s.s, -1);
            ++j;
        }
    }
    cout<<re<<endl;
}