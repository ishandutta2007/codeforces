#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=1e5+5, INF=1e9+5;
int dp[N][35], tab[N];
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tab[i];
    }
    int ans=0;
    for(int i=n-1; i>=0; i--){
        for(int j=30; j>=0; j--){
            if(tab[i]>j)dp[i][j]=0;
            else dp[i][j]=tab[i];
            if(tab[i]<=j && tab[i+1]<=j) dp[i][j]=max(dp[i][j], dp[i+1][j]+tab[i]);
            ans=max(ans, dp[i][j]-j);
        }
    }
    cout<<ans;
}