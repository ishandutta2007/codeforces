#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int ll
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

const int maxn = 1e5+5;

int l[17][2*3*maxn], r[17][2*3*maxn];
int a[maxn];

void build(int k){
    for (int o = 3*maxn-1; o>0; --o) {
        l[k][o] = min(l[k][o*2], l[k][o*2+1]);
        r[k][o] = max(r[k][o*2], r[k][o*2+1]);
    }
}

pii query(int L, int R, int k) {
    pii re = {1000000000,-1};
    for (L += 3*maxn, R += 3*maxn; L<R; L>>=1,R>>=1) {
        if (L & 1) {
            MX(re.s, r[k][L]); MN(re.f, l[k][L]);
            ++L;
        }
        if (R & 1) {
            --R;
            MX(re.s, r[k][R]); MN(re.f, l[k][R]);
        }
    }
    return re;
}

signed main(){
    IOS();
    int n; cin>>n;
    if(n==1) {
        cout<<0<<endl; return 0;
    }
    REP(i,n) {
        cin>>a[i];
        REP(j,3) l[0][i+j*n+3*maxn] = max(0,i+j*n-a[i]);
        REP(j,3) r[0][i+j*n+3*maxn] = min(3*n-1,i+j*n+a[i]);
    }
    build(0);
    for (int j = 1; j<17; ++j) {
        REP(i,3*n) {
            tie(l[j][i+3*maxn],r[j][i+3*maxn]) = query(l[j-1][i+3*maxn], r[j-1][i+3*maxn]+1,j-1);
        }
        build(j);
    }
//    return 0;
    REP(i,n) {
        int re = 0;
        int L = i+n, R = i+n;
        for(int j = 16; j>=0; --j) {
            pii np = query(L, R+1,j);
//            bug(np.s, np.f);

            if (np.s - np.f < n - 1) {
                tie(L,R) = np; re += 1<<j;
            }
        }
        cout<<re+1<<' ';
    }
}