#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+3;
ll n,b[N],dp[N],buc[N<<2],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		dp[i]=buc[N+b[i]-i]+b[i];
		buc[N+b[i]-i]+=b[i];
	}
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
	cout<<ans<<endl;
    return 0;
}