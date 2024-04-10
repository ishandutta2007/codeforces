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
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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

struct seg{
    int l,r;
    ll tg, bsum, s, cnt;
    seg(){
        l=r=tg=s=bsum=cnt=0;
    }
} T[maxn * 10 * 4];

vector<int> INDICES;
inline int GT(){
    int hi = INDICES.back(); INDICES.pop_back(); return hi;
}
//int IT = 1;

inline void push(int o) {
    if (T[o].tg) {
        T[o].s += T[o].bsum * T[o].tg;
        if (T[o].l) T[T[o].l].tg += T[o].tg;
        if (T[o].r) T[T[o].r].tg += T[o].tg;
        T[o].tg = 0;
    }
}

struct line{
    int l, r, o;
    int bat;
    bool operator < (const line & oth) const {
        return tie(l,r) < tie(oth.l, oth.r);
    }
};

void fre(int o) {
    if (!o) return;
    fre(T[o].l); fre(T[o].r);
    INDICES.pb(o); T[o] = seg();
}

void add(ll newb, ll numb, int o, int l=0, int r=maxn-1) {
    push(o);
    if (l == r) {
        bug(newb, numb, l,r);
        T[o].bsum = newb; T[o].s = newb * (numb+1); T[o].cnt = 1;
        return;
    }
    int mid = (l+r)/2;
    if (newb <= mid) {
        if (!T[o].l) T[o].l = GT();
        if (T[o].r) push(T[o].r);
        add(newb, numb + T[T[o].r].cnt,T[o].l,l,mid);
    }else{
        if (T[o].l) {
            T[T[o].l].tg ++;
            push(T[o].l);
        }
        if (!T[o].r) T[o].r = GT();
        add(newb,numb,T[o].r,mid+1,r);
    }
    T[o].s = T[T[o].r].s + T[T[o].l].s;
    T[o].bsum = T[T[o].r].bsum + T[T[o].l].bsum;
    T[o].cnt = T[T[o].r].cnt + T[T[o].l].cnt;
}

ll re = 0;
vector<int> bar[maxn];
int BIT = 0;

void addto(line &L, int B) {
    re -= T[L.o].s + T[L.o].bsum * L.l;
    add(B,0,L.o);
    re += T[L.o].s + T[L.o].bsum * L.l;
    bar[L.bat].pb(B);
}

void mrg(line &l1, line &l2) {
    re -= T[l1.o].s + T[l1.o].bsum * l1.l;
    re -= T[l2.o].s + T[l2.o].bsum * l2.l;
    bug("after sub");
    bug(re);
    if (SZ(bar[l1.bat]) < SZ(bar[l2.bat])) swap(l1,l2);
    fre(l2.o);
    bug(T[l1.o].s);
    for (int x : bar[l2.bat]) {
        bug("adding, ",x);
        add(x,0,l1.o);
        bar[l1.bat].pb(x);
        bug(T[l1.o].s);
    }
    MN(l1.l, l2.l);
    MX(l1.r, l2.r);
    bug(T[l1.o].bsum, l1.l, T[l1.o].s);
    re += T[l1.o].s + T[l1.o].bsum * l1.l;
}


signed main(){
    IOS();
    INDICES.resize(maxn*10*4);
    REP(i,maxn*10*4) INDICES[i]=i;
    int n; cin>>n;
    set<line> st;
    ll hi = 0;
    REP(i,n) {
        int a, b; cin>>a>>b;
//        b = n-b;
        hi += (b) * (a+1);
        auto it = (st.upper_bound({a,100000000}));
        line dat;
        if (it != st.begin() && prev(it)->r >= a-1) {
            --it;
            dat = *it;
            addto(dat,b);
            ++dat.r;
            st.erase(*it);
            it = next(st.insert(dat).f);
//            if (it != st.end()) {
//                bug(it->l);
//            }else bug("end");
//            bug("re after adding", re);
        }else{
            dat = {a,a,GT(),BIT++};
            addto(dat,b);
//            bug(T[dat.o].s);
//            re += a*b;
        }
        if (it != st.end() && it->l == dat.r + 1) {
            bug("mrggg");
            line hi=*it;
            st.erase(dat);
            st.erase(hi);
            mrg(dat, hi);
            bug(dat.l, dat.r);
            bug(hi.l, hi.r);
        }
        st.insert(dat);
        bug("gogogo");
//        for (auto &L : st) {
//            bug(L.l, L.r, SZ(bar[L.bat]));
//        }
        bug(re, hi);
        cout<<re-hi<<endl;
    }



}