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

const int maxn = 1.5e6;

int H[maxn];
int L[maxn], R[maxn];
bool A[maxn], B[maxn];
int n,m,k;

vector<int> inv (vector<int> & a) {
    vector<int> b (k);
    REP(i,k) {
        b[a[i]] = i;
    }
    return b;
}

string bin(int x) {
    string hi = "";
    REP(j,k) hi += (x & (1<<j))?'1':'0';
    return hi;
}

bool seen[maxn];
bool Luse[maxn], Ruse[maxn];
int pop[maxn];

signed main(){
    IOS();
    cin>>n>>m>>k;
    memset(H, -1, sizeof H);
    int num1 = 0, num2 = 0;
    REP(i, (1<<20)) {
        pop[i] = __builtin_popcount(i);
    }
    REP(i,k) {
        char c; cin>>c; A[i] = c=='1';
        num1 += A[i];
    }
    REP(i,k) {
        char c; cin>>c; B[i] = c=='1';
        num2 += B[i];
    }
    if (num1 > k/2) {
        REP(i,k) {
            A[i] ^= 1; B[i] ^= 1;
        }
        num1 = k-num1;
        num2 = k-num2;
    }
    vector<int> p(k); REP(i,k) p[i] = i;
    REP(i,n) {
        {
            vector<int> x = inv(p);
            REP(j,k) L[i] += (1<<j) * A[x[j]];
        }
        int a1, a2; cin>>a1>>a2; swap(p[a1-1], p[a2-1]);
        {
            vector<int> x = inv(p);
            REP(j,k) R[i+1] += (1<<j) * B[x[j]];
        }
    }
    bug("HI");
    REP(i,n) {
        bug(i,bin(L[i]));
        if (!seen[L[i]]) {
            seen[L[i]] = 1; Luse[i] = 1;
        }
    }
    memset(seen, 0, sizeof seen);
    for (int i = n-1; i>=0; --i) {
        bug(i+1,bin(R[i+1]));
        if (!seen[R[i+1]]) {
            seen[R[i+1]] = 1; Ruse[i+1] = 1;
        }
    }

    int res = -1;
    int rel = -1, rer = -1;
    for (int i = 1; i<=n; ++i) {
        int j = i-m;
        if ( j >= 0 && Luse[j]) {
            // add
            if (H[L[j]] == -1)
                for (int msk = L[j]; ; msk = (msk-1) & L[j]) {
                    H[msk] = j;
    //                bug(msk);
                    if (msk == 0) break;
                }
        }

        if (Ruse[i]){
            // query
            for (int msk = R[i]; ; msk = (msk-1) & R[i]) {
                if (~H[msk]) {
                    int bp = pop[(msk)];
                    if (bp > res) {
                        res = bp;
                        rel = H[msk]; rer = i;
                    }
                }
                if (msk == 0) break;
            }
        }
    }
    bug(res);
    bug(num1, num2);
    cout<<k - (num1 - res + num2 - res) <<endl;
    cout<<rel + 1 <<' '<<rer<<endl;

}