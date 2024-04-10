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

int x0,x1,Y0,Y1;
int lb, rb;
vector<pii> hi;

bool go(int r) {
    x0 = 0, x1 = 1e6+2, Y0=0, Y1=1e6+2;
    for (pii & p : hi) {
        x0 = max(x0, p.f - r);
        Y0 = max(Y0, p.s - r);
        x1 = min(x1, p.f+r);
        Y1 = min(Y1, p.s+r);
    }
    if (x0 > x1 || Y0 > Y1) return 0;
    lb = -1e6, rb = 1e6;
    for (pii & p : hi) {
        {
            int k = Y0 - (p.s-r);
            int X = p.f + k;
            rb = min(rb, X);
        }
        {
            int k = Y0 - (p.s);
            int X = p.f -r + k;
            lb = max(lb, X);
        }
    }

    if (lb > rb) return 0;
    bug(lb, rb);
    if (rb + Y1-Y0 >= x0 && lb <= x1) return 1;
    return 0;
}

signed main(){
    IOS();
    int n; cin>>n;
    for (int i = 0; i<n; ++i) {
        string s; cin>>s;
        pii mo = {0,0};
        for (char c : s){
            (c=='B'?mo.f:mo.s) ++;
        }
        hi.pb(mo);
        bug(mo.f, mo.s);
    }
    int l = 0, r = 1e6+1;
    while (l!=r) {
        int mid = (l+r)/2;
        if (!go(mid)) {
            l = mid+1;
        }else{
            r = mid;
        }

    }

    cout<<l<<endl;
    go(l);
    int nowx = -1, nowy = -1;

    if (rb <= x1) {
//            bug("HI"); return 0;
        nowx = rb, nowy = Y0;
    }else{
        nowx = lb; nowy = Y0;
    }
    while (!(nowx >= x0 && nowx <= x1 && nowy >= Y0 && nowy <= Y1) || (nowx == 0 && nowy == 0)) {
        ++nowx; ++nowy;
        bug(nowx, nowy);
    }
    bug(nowx, nowy);


    for (int i =0 ; i<nowx; ++i) cout<<'B';
    for (int i =0 ; i<nowy; ++i) cout<<'N';

}