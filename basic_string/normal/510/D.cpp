#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
const int N=1e5+3;
int f[N],g[N],l[N],a[N];
unordered_map<int,int>mp;
int main(){
	int n,i,j,k,o,u,t=0;
	for(scanf("%d",&n),i=1;i<=n;++i)scanf("%d",l+i);
	for(i=1;i<=n;++i){
		scanf("%d",&j),memcpy(f,g,t*4+4);
		for(k=t;k;--k){
			o=gcd(a[k],l[i]);
			if(u=mp[o],!u)mp[o]=++t,a[t]=o,f[t]=j+g[k];
			else f[u]=min(f[u],j+g[k]);
		}
		if(u=mp[l[i]],!u)mp[l[i]]=++t,a[t]=l[i],f[t]=j;else f[u]=min(f[u],j);
		memcpy(g,f,t*4+4);
	}
	if(mp[1])printf("%d",g[mp[1]]);else puts("-1");
	return 0;
}