#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+1;
const ll inf = 1e12;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}

int n,m,k;
int a[N],b[N],c[N],mx[N];
ll f[N][N];
vector<int>g[N];

int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i]=read();
		c[i]=read();
	}
	for(int i=1,x,val;i<=m;++i){
		val=read();x=read();
		mx[x]=max(mx[x],val);
	}
	for(int i=1;i<=n;++i){
		g[max(mx[i],i)].push_back(i);
	}
	for(int i=0;i<=n;++i)
	for(int j=0;j<N;++j){
		f[i][j]=-inf;
	}
	f[0][k]=0;
	for(int i=1;i<=n;++i){
		for(int j=a[i]+b[i];j<N;++j){
			f[i][j]=max(f[i][j],f[i-1][j-b[i]]);
		}
		for(int k=0;k<g[i].size();++k)
		for(int j=0;j<N-1;++j){
			f[i][j]=max(f[i][j],f[i][j+1]+c[g[i][k]]);
		}
	}
	ll ans=-inf;
	for(int i=0;i<N;++i)if(f[n][i]>ans)ans=f[n][i];
	if(ans<0)cout<<-1<<endl;
	else cout<<ans<<endl;
}