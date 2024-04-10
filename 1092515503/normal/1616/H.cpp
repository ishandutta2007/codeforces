#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,cnt=1,ch[5001000][2],sz[5001000],bin[150100];
#define lx ch[x][0]
#define rx ch[x][1]
#define ly ch[y][0]
#define ry ch[y][1]
void ins(int a){
	for(int i=29,x=1;i>=0;i--){
		if(!ch[x][(a>>i)&1])ch[x][(a>>i)&1]=++cnt;
		x=ch[x][(a>>i)&1];
		sz[x]++;
	}
}
int f(int x,int y,int i){
//	printf("F:%d,%d,%d\n",x,y,i);
	if(!x||!y||i==-1)return 1ll*(bin[sz[x]]-1)*(bin[sz[y]]-1)%mod;
	if(!((m>>i)&1))return(f(lx,ly,i-1)+f(rx,ry,i-1))%mod;
	int U=f(lx,ry,i-1),V=f(rx,ly,i-1);
	return(
		1ll*U*(bin[sz[ly]]+bin[sz[rx]]-1)+
		1ll*V*(bin[sz[lx]]+bin[sz[ry]]-1)+
		1ll*U*V+
		1ll*(bin[sz[lx]]-1)*(bin[sz[ly]]-1)+1ll*(bin[sz[rx]]-1)*(bin[sz[ry]]-1)
		)%mod;
}
int g(int x,int i){
//	printf("G:%d,%d\n",x,i);
	if(!x||i==-1)return bin[sz[x]]-1;
	if(!((m>>i)&1))return (g(lx,i-1)+g(rx,i-1))%mod;
	return(0ll+f(lx,rx,i-1)+(bin[sz[lx]]-1)+(bin[sz[rx]]-1))%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	bin[0]=1;for(int i=1;i<=n;i++)bin[i]=(bin[i-1]<<1)%mod;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),ins(x);
	printf("%d\n",g(1,29));
	return 0;
}
/*
3 12
3 15 11
*/