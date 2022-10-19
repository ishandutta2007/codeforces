#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=2005, INF=2e9+5, mod=1e9+7, A=30;
int dp[N][N];
int ile[A][N], ile2[A][N];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        for(int i=1; i<=n; i++){
            for(int j=0; j<A; j++){
                ile[j][i]=ile[j][i-1];
                ile2[j][i]=ile2[j][i-1];
            }
            ile[s[n-i]-'a'][i]++;
            ile2[t[n-i]-'a'][i]++;
        }
        dp[0][0]=0;
        for(int i=1; i<=n; i++){
            dp[0][i]=N;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n; j++){
                dp[i][j]=min(dp[i-1][j]+1, N);
                if(j && s[n-i]==t[n-j])dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
                if(j && ile[t[n-j]-'a'][i]>=ile2[t[n-j]-'a'][j]){
                    dp[i][j]=min(dp[i][j], dp[i][j-1]);
                }
            }
        }
        if(dp[n][n]!=N)cout<<dp[n][n]<<"\n";
        else cout<<"-1\n";
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                //cout<<dp[i][j]<<" ";
                dp[i][j]=0;
            }
            //cout<<"\n";
            for(int j=0; j<A; j++){
                ile[j][i]=0;
                ile2[j][i]=0;
            }
        }
    }
}