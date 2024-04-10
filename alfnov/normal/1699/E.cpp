#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int tj[5000005];
int f[5000005];
int da[5000005];
int mx;
void add(int x,int y){
	--da[x];
	++da[y];
	while(!da[mx])--mx;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		mx=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),mx=max(mx,a[i]);
		for(int i=1;i<=m;++i)tj[i]=0;
		for(int i=1;i<=n;++i)tj[a[i]]=1;
		int mn=m;
		for(int i=1;i<=n;++i)mn=min(mn,a[i]);
		for(int i=1;i<=m;++i)f[i]=i;
		int ans=INT_MAX;
		for(int i=1;i<=m;++i)da[i]=tj[i];
		for(int i=m;i>=1;--i){
			if(1ll*i*i<=m){
				for(int j=i*i;j<=m;j+=i){
					int cs=f[j];
					f[j]=min(f[j],f[j/i]);
					if(tj[j])add(cs,f[j]);
				}
			}
			if(i<=mn)ans=min(ans,mx-i);
		}
		printf("%d\n",ans);
	}
	return 0;
}