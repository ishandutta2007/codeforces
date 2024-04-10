#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
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

const int maxn = 1e5+5;

void ass(int x) {
    bug(x);
    if (x%2==1) GG();
}

signed main(){
    IOS();
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int T = (d+a+b); ass((d+a+b)); T/=2;
    int A = T-b, B = T-d, C = T-a;
    if (A<0 || B<0 || C<0) ass(1);
    bug(A,B,C);
    ass(c-f+B+C); ass(c-e+A+B); ass(f-e+A-C);
    int al = (f-e+A-C)/2, be = (c-f+B+C)/2, de=(c+e-A-B)/2;
    bug(de);
    int ga = 0;
    while (ga<C && be>0 && al<A && de>0) {
        ga++; al++; be--; de--;
    }
    if (be>B||be<0||al>A||al<0||de<0) ass(1);
    int n = A+B+C+de;
    cout<<n<<endl;
    REP(i,n) cout<<'a'; cout<<endl;
    REP(i,A+B) cout<<'b'; REP(i,n-A-B) cout<<'a';
    cout<<endl;
    REP(i,A) cout<<'a'; REP(i,B+C) cout<<'b'; REP(i,n-A-B-C) cout<<'a';
    cout<<endl;
    REP(i,al) cout<<'b'; REP(i,A-al) cout<<'a';
    REP(i,be) cout<<'b'; REP(i,B-be) cout<<'a';
    REP(i,ga) cout<<'b'; REP(i,C-ga) cout<<'a';
    REP(i,n-A-B-C) cout<<'b';
    cout<<endl;

}