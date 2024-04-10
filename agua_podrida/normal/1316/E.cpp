#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

const int N = 1e5+5;
ll dp[N][(1<<7)+1];
ll b[N][7];
ll a[N];
int ind[N];

bool cmp(int i, int j){
    return a[i] > a[j];
}

void e(){
    int n,p,k;
    cin>>n>>p>>k;
    memset(dp,-1,sizeof(dp));

    F1(i,n) cin>>a[i];
    F1(i,n) F0(j,p) cin>>b[i][j];
    F1(i,n) ind[i] = i;
    sort(ind+1,ind+n+1,cmp);

    dp[0][0] = 0;

    F1(i,n){
        int pos = ind[i];
        F0(bit,(1<<p)){
            int selected = 0;
            F0(j,p) if(bit & (1<<j)) selected++;
            if(dp[i-1][bit] != -1) {
                if(selected + k >= i) dp[i][bit] = dp[i-1][bit] + a[pos];
                else dp[i][bit] = dp[i-1][bit];
            }

            F0(j,p){
                if(bit & (1<<j) and dp[i-1][(bit ^ (1<<j))] != -1){
                    ll z = dp[i-1][(bit ^ (1<<j))] + b[pos][j];
                    if(z > dp[i][bit]) dp[i][bit] = z;
                }
            }
        }
    }

    cout<<dp[n][(1<<p)-1]<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    e();
    return 0;
}