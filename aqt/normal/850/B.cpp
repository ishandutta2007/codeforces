#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 500005
#define MAXV 2000005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int N,X,Y,arr[MAXN],psa[MAXV];
ll sums[MAXV];
ll res = LL_INF;

int main(){
//    int st = clock();
    fastio; cin >> N >> X >> Y;
    for(int i=1; i<=N; i++)
        cin >> arr[i], psa[arr[i]]++, sums[arr[i]]+=arr[i];
    for(int i=2; i<=2e6; i++)
        psa[i]+=psa[i-1], sums[i]+=sums[i-1];
//    res = 1LL*(N-1)*X;
    for(int i=2; i<=2e6; i++){
        ll cost = 0;
        for(int k=i; k<=2e6; k+=i){
            int am = psa[k]-psa[k-i];
            //min(X,(k-j)*Y)
            //kY-jY > X
            //jY < kY-X
            //j < (ky-X)/Y
            ll idx = (1LL*k*Y-X)/Y;
//            if(idx*Y == 1LL*k*Y-X) idx--;
            if(idx <= k-i){
                ll v = 1LL*k*am-(sums[k]-sums[k-i]);
                cost+=v*Y;
            }else if(idx > k) cost+=1LL*X*am;
            else{
                ll v = 1LL*k*(psa[k]-psa[idx])-(sums[k]-sums[idx]);
                cost+=v*Y;

                v = psa[idx]-psa[k-i];
                cost+=v*X;
            }
        }
        res = min(res,cost);
    }
    cout << res << endl;
}