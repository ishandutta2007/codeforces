#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m[1005],G[1005],K[1005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>m[i];
	for(int pos=1;pos<=n;pos++){
		ll tmp=1e9;
		for(int i=pos;i;i--){
			tmp=min(tmp,m[i]);
			G[i]=tmp;
		}
		tmp=1e9;
		for(int i=pos;i<=n;i++){
			tmp=min(tmp,m[i]);
			G[i]=tmp;
		}
		ll sum=0;
		for(int i=1;i<=n;i++)sum+=G[i];
		if(sum>ans)for(int i=1;i<=n;i++)K[i]=G[i],ans=sum;
	}
	for(int i=1;i<=n;i++)cout<<K[i]<<" ";
    return 0;
}