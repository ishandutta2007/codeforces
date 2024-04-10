#include<bits/stdc++.h>
using namespace std;
struct col{
	int a[15],mx;
}b[2001];
int T,n,m,f[15][5001],g[5001];
int lowbit(int x){return x&(-x);}
bool comp(col x,col y){return x.mx>y.mx;}
void calg(col x){
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++){
		int nt=x.a[1];
		for(int j=1;j<n;j++)x.a[j]=x.a[j+1];x.a[n]=nt;
		for(int j=0;j<(1<<n);j++){
			int na=0;
			for(int k=1;k<=n;k++)if(j&(1<<(k-1)))na+=x.a[k];
			g[j]=max(g[j],na);
		}
	}
}
signed main(){
//	freopen("late.in","r",stdin);
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));memset(b,0,sizeof(b));
		cin>>n>>m;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>b[j].a[i],b[j].mx=max(b[j].mx,b[j].a[i]);
		sort(b+1,b+m+1,comp);
		for(int i=1;i<=min(n,m);i++){
			calg(b[i]);
			for(int j=0;j<(1<<n);j++){
				for(int k=lowbit(j);k;k^=((lowbit(k^j)<<1)-1)&j){
					f[i][j]=max(f[i][j],f[i-1][k]+g[j^k]);
				}
				f[i][j]=max(f[i][j],f[i-1][0]+g[j]);
			}
		}
		cout<<f[min(n,m)][(1<<n)-1]<<endl;
	}
	return 0;
}
/*

*/