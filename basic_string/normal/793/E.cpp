#include<bits/stdc++.h>
using namespace std;
const int N=5003;
int cl[N],sz[N],ct1[N],ct2[N],y,n;
basic_string<int>g[N];
bitset<N/2>w,w2;
void dfs(int x){
	if(g[x].size())for(int i:g[x])dfs(i),sz[x]+=sz[i],cl[x]+=cl[i];
	else ++y,sz[x]=1;
}
void get(int x,int*c){for(int i:g[x])if(cl[i])get(i,c);else ++c[sz[i]];}
void wk(bitset<N/2>&w,int*c){
	int i,j,k;
	for(i=1;i<=n;++i)if(c[i]){
		for(j=1,k=c[i];j<k;j*=2)k-=j,w|=w<<i*j;
		w|=w<<i*k;
	}
}
int main(){
	int a,b,c,d,i,j;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d),cl[a]=1,cl[b]=2,cl[c]=3,cl[d]=4;
	for(i=2;i<=n;++i)scanf("%d",&j),g[j]+=i;
	for(int i:g[1]){
		dfs(i);
		if(j=cl[i]){
			if(j<3)get(i,ct1);else get(i,ct2);
			if(j==3)w[sz[i]]=1;
			if(j==2)w2[sz[i]]=1;
		}else ++ct1[sz[i]],++ct2[sz[i]];
	}
	if(y&1)puts("No"),exit(0);
	wk(w,ct1),wk(w2,ct2);
	if(j=y/2-1,w[j]&&w2[j])puts("Yes");else puts("No");
	return 0;
}