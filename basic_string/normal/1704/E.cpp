#include<bits/stdc++.h>
using namespace std;
enum{N=1009,P=998244353};
bool b[N];
basic_string<int>e[N];
int d[N],a[N],dg[N],d2[N],s[N][N],ans[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>m;
		for(i=1;i<=n;++i)cin>>a[i],e[i]={},b[i]=0,d[i]=0,
		dg[i]=0,d2[i]=0,memset(s[i],0,sizeof s[i]),ans[i]=0;
		while(m--)cin>>i>>j,e[i]+=j,++dg[j],++d2[j];
		queue<int>q;
		for(i=1;i<=n;++i)if(!dg[i])q.push(i);
		while(q.size()){
			i=q.front();q.pop();
			if(a[i])b[i]=1;
			for(int o:e[i]){
				d[o]=max(d[o],d[i]+1);
				b[o]|=b[i];
				if(!(--dg[o]))q.push(o);
			}
		}
		if(!b[i]){cout<<0<<'\n';continue;}
		int mx=d[i];
		for(i=1;i<=n;++i)if(!d2[i])q.push(i);
		while(q.size()){
			i=q.front();q.pop();
			ans[i]=(ans[i]+a[i])%P;
			s[i][0]+=a[i];
			for(j=0;j<mx;++j){
				if(s[i][j])--s[i][j+1];
				s[i][j+1]+=s[i][j];
			}
			for(int o:e[i]){
				for(j=0;j<mx;++j)if(s[i][j])++s[o][j+1];
				ans[o]=(ans[o]+ans[i])%P;
				if(!(--d2[o]))q.push(o);
			}
		}
		int anss=ans[i];
		for(j=0;j<mx;++j)if(!s[i][j])anss=(anss+1)%P;
		cout<<(anss+P)%P<<'\n';
	}
}