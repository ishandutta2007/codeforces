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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 998244353 ;


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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 5005;//

bool ok[maxn][maxn];

signed main(){
    IOS();
    string s; cin>>s;
    int n = s.length();
    int K = floor(log2(n));
    bug(K);
    int left = n- (1<<K) + 1;
    ok[0][0] = 1;
    string re = "";
    int cap = (1<<K);
    for (int j = 0; j<left; ++j) { // taken
        char bst = 'z';
        for (int i = 0; i<min(j+cap, n); ++i) {
            if (ok[j][i]) {
                bug(j,i);
                bst = min(bst, s[i]);
                int tk = i - j;
                for (int k = 0; k<K; ++k){
//                    bug(k);
                    if (((tk&(1<<k)) == 0) && (i+(1<<k)) < n) {
                        ok[j][i+(1<<k)] = 1;
                        bug(j,i+(1<<k));
                    }
                }
            }
        }
        re += bst;
        if (j != left-1) for (int i = 0; i<min(j+cap, n); ++i) {
            if (ok[j][i] && s[i] == bst) {
                // update bois
                ok[j+1][i+1] = 1;
            }
        }
    }

    cout<<re<<endl;
}