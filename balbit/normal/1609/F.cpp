#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 zck_is_king
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

const int maxn = 1e6+5;

int col[maxn];
int a[maxn];
ll raw[maxn];
int Mx[maxn], Mn[maxn];
ll re = 0;
int mxon[61], mnon[61];
int both, lose;

void dnc(int l, int r) {
    if (r-l <= 15) {
        for (int i = l; i<=r; ++i) {
            int mx = -1, mn = -1;
            for (int j = i; j<=r; ++j) {
                if (mx == -1 || a[j] > a[mx]) mx = j;
                if (mn == -1 || a[j] < a[mn]) mn = j;
                re += col[mx] == col[mn];
//                if (col[mx] == col[mn]) bug(i,j,col[mx],re);
//                if (i ==c
            }
        }
        return;
    }
    int mid = (l+r)/2;

    int mx = -1, mn = -1;
    both = lose = 0;
    for (int rp = mid+1; rp <= r; ++rp) {
        if (mx == -1 || a[rp] > a[mx]) mx = rp;
        if (mn == -1 || a[rp] < a[mn]) mn = rp;
        Mx[rp] = mx; Mn[rp] = mn;
        lose += col[mx] == col[mn];
//        ++losemx[col[mx]];
//        ++losemn[col[mn]];
    }
    mx = -1; mn = -1;
    int beatmx = mid+1, beatmn = mid+1;
    for (int lp = mid; lp >= l; --lp) {
        if (mx == -1 || a[lp] > a[mx]) mx = lp;
        if (mn == -1 || a[lp] < a[mn]) mn = lp;
        while (beatmx <= r && a[mx] > a[Mx[beatmx]]) {
            if (beatmn <= beatmx) {
                lose -= col[Mx[beatmx]] == col[Mn[beatmx]];
//                --losemx[col[Mx[beatmx]]];
//                --losemn[col[Mn[beatmx]]];
                ++mxon[col[Mn[beatmx]]];
            }else{
                --mnon[col[Mx[beatmx]]];
                ++both;
            }
            ++beatmx;
        }
        while (beatmn <= r && a[mn] < a[Mn[beatmn]]) {
            if (beatmx <= beatmn) {
                lose -= col[Mx[beatmn]] == col[Mn[beatmn]];
                ++mnon[col[Mx[beatmn]]];
            }else{
                --mxon[col[Mn[beatmn]]];
                ++both;
            }
            ++beatmn;
        }
        if (col[mn] == col[mx]) re += both;
        re += lose;
        bug(lose);
        re += mnon[col[mn]] + mxon[col[mx]];
    }

    memset(mxon, 0, sizeof mxon);
    memset(mnon, 0, sizeof mnon);
    dnc(l,mid); dnc(mid+1,r);
}

signed main(){
    IOS();
    int n; cin>>n;
    vector<pair<ll, int> > v;
    REP(i,n) {
        cin>>raw[i];
        v.pb({raw[i], i});
    }
    sort(ALL(v));
    REP(i, n) {
        a[i] = lower_bound(ALL(v), pair<ll, int>{raw[i], i}) - v.begin();
        col[i] = __builtin_popcountll(raw[i]);
        bug(a[i], col[i]);
    }
    dnc(0,n-1);
    cout<<re<<endl;


}