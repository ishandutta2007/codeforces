#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,d,a[N];
bool p[N];
int main(){
	//freopen("p.in","r",stdin);
	//freopen("p.out","w",stdout);
	cin>>t;
	memset(p,1,sizeof(p));int maxer;
	for(int i=2;i<=1000;i++)if(p[i])
		for(int j=2;i*j<=N;j++)p[i*j]=0;
	for(int i=1;i<=N;i++)if(p[i])maxer=i;

	a[maxer]=maxer;
	for(int i=maxer-1;i>=1;i--)
		if(p[i])a[i]=i;else a[i]=a[i+1];
	for(int xx=1;xx<=t;xx++){
		cin>>d;
		long long ans;
		ans=a[1]*a[d+1]*a[a[d+1]+d];
		cout<<ans<<endl;
	}
	return 0;
}