#include<bits/stdc++.h>
using namespace std;
enum{N=5009};
using ll=long long;
int ct1[N],p[N],ct2[N][N];
ll ans;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,l;
	for(cin>>T;T--;){
	ans=0;	cin>>n;
	for(i=1;i<=n;++i)cin>>p[i],memset(ct2[i],0,n*4+4);
	for(i=n;i;--i){
		for(j=1;j<=p[i];++j)ct2[i-1][j]=ct2[i][j];
		for(j=p[i]+1;j<=n;++j)ct2[i-1][j]=ct2[i][j]+1;
	}
	memset(ct1,0,n*4+4);
	for(i=1;i<=n;++i){
	//	memset(ct2,0,n*4+4);
		for(j=n;j>i;--j){
			ans+=ct2[j][p[i]]*ct1[p[j]];
		}
		for(j=p[i]+1;j<=n;++j)++ct1[j];
	}
	cout<<ans<<'\n';
	}
}