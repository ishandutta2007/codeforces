// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
int n,a[maxn],ans;
map<int,int>dp;
vector<int>v;
int main(){
	IOS
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);
		ans=max(ans,dp[a[i]]);
	}
	for(int i=n;i>=1;i--){
		if(dp[a[i]]==ans){
			int x=a[i];
			while(i){
				if(a[i]==x){
					v.pb(i);
					x--;
				}
				i--;
            }
           	break;
		}
	}
	cout<<v.size()<<endl;
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i]<<" ";
}