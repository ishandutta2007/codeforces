#include <bits/stdc++.h>
using namespace std;

int t,n,x[105],ans,buc[105];

int main(){
	cin>>t;
	while(t--){
		ans=0,cin>>n,memset(buc,0,sizeof(buc));
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=!buc[x[j]-x[i]],buc[x[j]-x[i]]=1;
		cout<<ans<<endl;
	}
	return 0;
}