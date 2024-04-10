#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("Ofast")
using namespace std;
int n,m,x[200005],y[200005],z[200005],f[605][605],ans;
vector<int> v[200005],e[200005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",x+i,y+i);
	}
	for(int i=1;i<=m;++i){
		int op,k;
		scanf("%d%d",&op,&k);
		if(op==1){
			z[k]=i;
			if(x[k]+y[k]<=600){
				int s=x[k]+y[k];
				int l=(i+x[k])%s,r=i%s;
				if(l<r)for(int j=l;j<r;++j)++f[s][j];
				else{
					for(int j=l;j<s;++j)++f[s][j];
					for(int j=0;j<r;++j)++f[s][j];
				}
			}
			else{
				if(i+x[k]<=m){
					v[i+x[k]].pb(k);
					e[i+x[k]].pb(i);
				}
			}
		}
		else{
			if(x[k]+y[k]<=600){
				int s=x[k]+y[k];
				for(int j=z[k]+x[k];j<z[k]+s;++j)--f[s][j%s];
			}
			else{
				int o=(i-z[k])%(x[k]+y[k]);
				if(o>x[k]||o==0)--ans;
			}
			z[k]=0;
		}
		for(int j=0;j<v[i].size();++j){
			int k=v[i][j];
			if(e[i][j]!=z[k]) continue;
			if((i-z[k])%(x[k]+y[k])){
				++ans;
				if(i+y[k]<=m)v[i+y[k]].pb(k),e[i+y[k]].pb(z[k]);
			}
			else{
				--ans;
				if(i+x[k]<=m)v[i+x[k]].pb(k),e[i+x[k]].pb(z[k]);
			}
		}
		int res=ans;
		for(int j=1;j<=600;++j)res+=f[j][i%j];
		printf("%d\n",res);
	}
    return 0;
}