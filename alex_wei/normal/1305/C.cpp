#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[200005],p[200005],z[200005],buc[2005],ans=1;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=c[i]%m;
		if(z[p[i]])puts("0"),exit(0);
		z[p[i]]=1;
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=ans*abs(c[i]-c[j])%m;
	cout<<ans<<endl;
	return 0;
}