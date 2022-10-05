#include<bits/stdc++.h>
using namespace std;
int x[1009],y[1009];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k;
	bool b0,b1;
	cin>>n;
	for(i=1;i<=n;++i)cin>>x[i]>>y[i];
	while(1){
		b0=b1=0;
		for(i=1;i<=n;++i)if(x[i]+y[i]&1)b1=1;else b0=1;
		if(b0&&b1){
			for(i=1,j=0;i<=n;++i)if(x[i]+y[i]&1)++j;
			cout<<j<<'\n';
			for(i=1;i<=n;++i)if(x[i]+y[i]&1)cout<<i<<' ';
			return 0;
		}
		if(b1)for(i=1;i<=n;++i)--x[i];
		for(i=1;i<=n;++i)j=x[i],k=y[i],x[i]=j+k>>1,y[i]=j-k>>1;
	}
	return 0;
}