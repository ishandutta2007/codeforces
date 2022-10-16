#include<bits/stdc++.h>
typedef std::bitset<2002>bits;
int n,m,q;
int cnt[2222];
bits w[2222],__1[2222];
void reverse(int x,int l,int r)
{
	w[x]^=__1[r-l+1]<<l;
	cnt[x]=w[x].count();
}
struct comp
{bool operator()(const int x,const int y)const{return(cnt[x]!=cnt[y])?cnt[x]<cnt[y]:x<y;}};
std::set<int,comp>S;
std::vector<int>INV;
void report(int x1,int x2)
{
	bits B=w[x1]^w[x2],B1=B&w[x1],B2=B&w[x2];
	int y1=B1._Find_first(),y2=B2._Find_first();
	if(x1>x2){int t=x1;x1=x2,x2=t;}
	if(y1>y2){int t=y1;y1=y2,y2=t;}
	printf("%d %d %d %d\n",x1,y1,x2,y2); 
}
void tryIns()
{
	while(INV.size())
	{
		int T=INV.back();
		int pre=*--S.lower_bound(T),nxt=*S.upper_bound(T);
		if(pre)if((w[T]&w[pre])!=w[pre])return report(pre,T);
		if(nxt!=n+1)if((w[T]&w[nxt])!=w[T])return report(T,nxt);
		S.insert(T),INV.pop_back();
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	register int i;
	cnt[0]=-1e9,cnt[n+1]=1e9;
	for(i=0;i<=n+1;i++)S.insert(i);
	for(i=1;i<=m;i++)__1[i]=__1[i-1],__1[i][i-1]=1;
	for(i=1;i<=q;i++)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		if(S.find(x)!=S.end())S.erase(x),INV.push_back(x);
		reverse(x,l,r),tryIns();
		if(!INV.size())puts("-1");
	}
}
/*
This end-of-file is just the beginning.
*/