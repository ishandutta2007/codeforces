#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,m,f[500005],res[500005],r,bi[500005];
int get(int x){return x==f[x]?x:f[x]=get(f[x]);}
int main(){
	scanf("%d%d",&n,&m);
	bi[0]=1;
	for(int i=1;i<=m+1;++i)f[i]=i;
	for(int i=1;i<=m;++i)bi[i]=bi[i-1]*2%orz;
	for(int i=1;i<=n;++i){
		int k,x,y;
		scanf("%d",&k);
		if(k==1){
			scanf("%d",&x);
			y=m+1;
		}
		else{
			scanf("%d%d",&x,&y);
		}
		if(get(x)!=get(y)){
			f[f[x]]=f[y];
			res[++r]=i;
		}
	}
	printf("%d %d\n",bi[r],r);
	for(int i=1;i<r;++i)printf("%d ",res[i]);
	printf("%d\n",res[r]);
    return 0;
}