#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,num[101000],cnt[101000],res,f[100100],g[100100];
int u,v;
void Push(int x){
	res+=cnt[num[x]],cnt[num[x]]++;
}
void Pop(int x){
	cnt[num[x]]--,res-=cnt[num[x]];
}
int Calc(int l,int r){
	while(u>l)Push(--u);
	while(v<r)Push(++v);
	while(u<l)Pop(u++);
	while(v>r)Pop(v--);
	return res;
}
void solve(int l,int r,int L,int R){
	if(l>r||L>R)return;
	int mp=-1,mn=0x3f3f3f3f3f3f3f3f,mid=(l+r)>>1;
	for(int i=L;i<=R;i++){
		int tmp=Calc(i+1,mid);
		if(f[i]+tmp<mn)mp=i,mn=f[i]+tmp;
	}
	g[mid]=mn;
	solve(l,mid-1,L,mp),solve(mid+1,r,mp,R);
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
	u=v=1,cnt[num[1]]++;
	for(int i=1;i<=n;i++)f[i]=Calc(1,i);
	while(--m)solve(1,n,0,n-1),memcpy(f,g,sizeof(g));
	printf("%lld\n",f[n]);
	return 0;
}