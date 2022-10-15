#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 2e5+5;

int tag[maxn*4], s[maxn*4];

void push(int o, int l, int r){
    if (!tag[o]) return;
    s[o]+=tag[o];
    if (l!=r){
        tag[o*2+1]+=tag[o];
        tag[o*2+2]+=tag[o];
    }
    tag[o]=0;
}

int QU(int o, int l, int r, int L, int R){ // RMQ
    if (l>R||r<L) return -100000000000;
    push(o,l,r);
    if (l>=L&&r<=R) return s[o];
    int mid = (l+r)/2;
    int ql = QU(o*2+1,l,mid,L,R), qr = QU(o*2+2,mid+1,r,L,R);
    return max(ql,qr);
}

void MO(int o, int l, int r, int L, int R, int v){
    push(o,l,r);
    if (l>R||r<L) return;
    if (l>=L&&r<=R) {
        tag[o]+=v; push(o,l,r); return;
    }
    int mid = (l+r)/2;
    MO(o*2+1,l,mid,L,R,v);
    MO(o*2+2,mid+1,r,L,R,v);
    s[o]=max(s[o*2+1],s[o*2+2]);
}

vector<pii> a; // amt, cost
vector<pii> d; // defense

struct Mon{
    int d,a,c;
};

signed main(){
    IOS();
    int n,m,p; cin>>n>>m>>p;
    for (int i = 0; i<n; i++) {
        int x,y; cin>>x>>y; a.pb({x,y});
    }
    sort(ALL(a));
    for (int i = 0; i<m; i++) {
        int x,y; cin>>x>>y; d.pb({x,y});
    }
    sort(ALL(d));
    vector<int> b(m);
    for (int i = 0; i<m; i++) {
        b[i] = d[i].f;
        MO(0,0,m-1,i,i,-d[i].s);
    }
    vector<Mon> mm;
    for (int i = 0; i<p; i++) {
        int x,y,z; cin>>x>>y>>z;
        mm.pb({x,y,z});
    }
    sort(ALL(mm),[&](Mon a,Mon b){return a.d<b.d;});
    int it = 0;
    ll re = -100000000000ll;
    for (int i = 0; i<n; i++) {
        while (it < p && mm[it].d < a[i].f) {
            int j = upper_bound(ALL(b), mm[it].a) - b.begin();
            bug(it, j);
            MO(0,0,m-1,j, m-1, mm[it].c);
            ++it;
        }
        re = max(re, (ll)(-a[i].s + s[0]));
    }
    cout<<re<<endl;
}