#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int f[N],nx[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){
	int n,q,i,j,k,l,o;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)f[i]=i,nx[i]=i+1;
	while(q--){
		scanf("%d%d%d",&i,&j,&k);
		if(i==1)f[gf(j)]=gf(k);
		else if(i==2){
			for(l=j+1;l<=k;l=o){
				f[gf(l-1)]=gf(l),o=nx[l],nx[l]=nx[k];
			}
		}else puts(gf(j)==gf(k)?"YES":"NO");
	}
	return 0;
}