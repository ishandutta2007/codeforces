#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=5005, INF=1e9+5, mod=1e9+7;
int dp[N][N];
int main(){
    int n, m;
    cin>>n>>m;
    str s, t;
    cin>>s>>t;
    s='#'+s;
    t='#'+t;
    for(int i=1; i<=n; i++)dp[i][0]=-i;
    for(int i=1; i<=m; i++)dp[0][i]=-i;
    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i]==t[j]){
                dp[i][j]=max(dp[i-1][j-1], 0)+2;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1])-1;
            }
            //cout<<dp[i][j]<<" ";
            ans=max(ans, dp[i][j]);
        }
        //cout<<"\n";
    }
    cout<<ans;
}