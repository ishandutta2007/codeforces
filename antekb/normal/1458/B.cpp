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

const int N=101, INF=1e9+5, mod=1e9+7;
int dp[N][N*N], czy[N][N*N];
int main(){
    int n;
    cin>>n;
    vector<int> A(n), B(n);
    int sum=0;
    czy[0][0]=1;
    for(int i=0; i<n; i++){
        cin>>A[i]>>B[i];
        sum+=B[i];
        for(int j=i; j>=0; j--){
            for(int k=0; k<N*N; k++){
                if(!czy[j][k])continue;
                dp[j+1][k+A[i]]=max(dp[j][k]+B[i], dp[j+1][k+A[i]]);
                czy[j+1][k+A[i]]=1;
            }
        }
    }
    for(int j=1; j<=n; j++){
        int ans=0;
        for(int k=0; k<N*N; k++){
            //cout<<dp[j][k]<<" ";
            if(czy[j][k])ans=max(ans, min(2*k, dp[j][k]+sum));
        }
        //cout<<"\n";
        cout<<fixed<<setprecision(1)<<((ld)ans)/2<<"0000000000 ";
    }
}