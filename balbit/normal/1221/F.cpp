#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e6+5;

struct pt{
    ll x, y, c;
};

pair<ll,int> s[maxn*4];
ll tg[maxn*4];

void push(int o, int l, int r) {
    if (!tg[o]) return;
    s[o].f += tg[o];
    if (l != r) {
        tg[o*2] += tg[o];
        tg[o*2+1] += tg[o];
    }
    tg[o]=0;
}

void MO(int L, int R, int v, int o = 1, int l = 0, int r = maxn-1) {
    push(o,l,r);
    if (l > R || r < L) return;
    if (l>=L && r <= R) {
        tg[o] += v; push(o,l,r);
        return;
    }
    int mi = (l+r)/2;
    MO(L,R,v,o*2,l,mi);
    MO(L,R,v,o*2+1,mi+1,r);
    s[o] = min(s[o*2], s[o*2+1]);
}

void build(int o=1, int l=0, int r=maxn-1) {
    if (l == r) s[o] = {0,l};
    else{
        int mid = (l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
        s[o] = min(s[o*2+1], s[o*2]);
    }
}


signed main(){
    IOS();
    build();
    int n; cin>>n;
    vector<pt> v;
    set<pair<ll, int> > st;
    map<int, ll> mp; // maps y position to current sum
    map<ll, int> redy;
    vector<int> tmpy;
    for (int i = 0; i<n; ++i) {
        int x,y,c; cin>>x>>y>>c;
        if (x < y) swap(x,y);
        tmpy.pb(y);
        v.pb({x,y,c});
    }
    SORT_UNIQUE(tmpy);
    for (int i = 0; i<SZ(tmpy); ++i) redy[tmpy[i]] = i;

    sort(ALL(v),[&](pt a, pt b){return a.x < b.x;});
    ll re = -1;
    int frm = -1, to = -1;
    int j = 0;
    for (int i =0; i<n; ++i) {
        while (j < SZ(tmpy) && tmpy[j] <= v[i].x) {
            MO(j,j,-tmpy[j]); ++j;
        }
        MO(0,redy[v[i].y],-v[i].c);
//        st.erase(make_pair(mp[v[i].y], v[i].y));
//        mp[v[i].y] += -v[i].c;
//        st.insert(make_pair(mp[v[i].y], v[i].y));
//        bug(v[i].y, mp[v[i].y]);
        if (i == n-1 || v[i+1].x != v[i].x) {
            ll tmp = -v[i].x - s[1].f;
            bug(tmp, s[1].f, s[1].s);
//            bug(st.begin()->f);
            if (tmp > re && tmpy[s[1].s] <= v[i].x) {
                re = tmp;
                frm = tmpy[s[1].s], to = v[i].x;
            }

        }
    }
    if (re != -1)
        cout<<re<<endl<<frm<<' '<<frm<<' '<<to<<' '<<to<<endl;
    else{
        cout<<0<<endl;
        tmpy.pb(2e9+3);
        for (int i = 0; i<SZ(tmpy); ++i) {
            if (tmpy[i+1] - tmpy[i] > 1) {
                for (int j = 0; j<4; ++j) cout<<tmpy[i]+1<<' ';
                return 0;
            }
        }
    }

}