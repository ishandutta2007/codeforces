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

const int maxn = 2e5+5;
//const int maxa = 2e5+5;
struct seg{
    int l=0, r=0;
    int v=0;
}s[maxn*4*18];

int IT = 1;
int H[maxn];
bool np[maxn];
vector<int> pf[maxn];

vector<int> sp, bp;
queue<int> pos[maxn];

void build(){
    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) {
            if (i * (ll)i < maxn) sp.pb(i);
            else bp.pb(i);
            pf[i].pb(i);
            for (int j = i+i; j<maxn; j += i) {
                np[j] = 1;
                int tmp = j;
                while (tmp % i == 0) {
                    tmp /= i;
                    pf[j].pb(i);
                }
            }
        }
    }
}

void BUILD(int &o, int l=0, int r=maxn-1){
    o = IT++;
    s[o].v = 1;
    if (l == r) {
        return;
    }
    int mid = (l+r)/2;
    BUILD(s[o].l, l, mid);
    BUILD(s[o].r, mid+1, r);
}

void MO(int p, int v, int &o, int l=0, int r=maxn-1) {
    if (l > p || r < p) return;
    int tmp = o;
    o = IT++;
    s[o] = s[tmp];
    if (l ==r) {
        s[o].v = v;
        return;
    }
    int mid = (l+r)/2;
    MO(p, v, s[o].l, l, mid);
    MO(p, v, s[o].r, mid+1, r);
    s[o].v = s[s[o].l].v * (ll) s[s[o].r].v % mod;
}

ll QU(int L, int R, int o, int l=0, int r=maxn-1) {
    if (l > R || r < L) return 1;
    if (l >= L && r <= R) return s[o].v;
    int mid = (l+r)/2;
    return QU(L,R,s[o].l,l,mid) * QU(L,R,s[o].r,mid+1,r) % mod;
}

int a[maxn];

struct zck{
    int s[2*maxn];
    void build() {
        for (int i = maxn-1; i>0; --i) s[i] = max(s[i*2], s[i*2+1]);
    }
    int QU(int l, int r) {
        int re = 0;
        for (l += maxn, r += maxn; l < r; l/=2, r/=2) {
            if (l & 1) re = max(re, s[l++]);
            if (r & 1) re = max(re, s[--r]);
        }
        return re;
    }
}rmq[88];

int here[maxn];

signed main(){
    IOS();
    s[0].v=1;
    build();
    bug(SZ(sp));
    int n; cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>a[i];
        for (int x : pf[a[i]]) {
            if (x * (ll) x > maxn) {
                pos[x].push(i);
                here[i] = x;
            }else{
                int p = lower_bound(ALL(sp), x) - sp.begin();
                rmq[p].s[maxn+i] ++;
            }
        }
    }
    for (int i = 0; i<88; ++i) rmq[i].build();
    BUILD(H[0]);
    for (int i = 0; i<maxn; ++i) {
        if (!pos[i].empty()) {
            MO(pos[i].front(), i, H[0]);
            pos[i].pop();
        }
    }
    for (int i = 0; i<n; ++i) {
        H[i+1] = H[i];
        if (here[i] != 0 && !pos[here[i]].empty()) {
            MO(pos[here[i]].front(), here[i], H[i+1]);
            pos[here[i]].pop();
        }
    }

    int q; cin>>q;
    ll last = 0;
    while (q--) {
        int l, r; cin>>l>>r;
        (l+=last)%=n;
        (r+=last)%=n;
        if (l > r) swap(l,r);
        last = 1;
        for (int i = 0; i<SZ(sp); ++i) {
            last *= mpow(sp[i], rmq[i].QU(l,r+1));
            last %= mod;
        }
        bug(last);
        last *= QU(l,r,H[l]) ; last %= mod;
        cout<<last<<endl;
    }


}