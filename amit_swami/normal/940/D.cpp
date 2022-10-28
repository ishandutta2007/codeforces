#include<bits/stdc++.h>
using namespace std;
const int MAXN=520233;
const int INF=1e9;
int n,a[MAXN+10],l=-INF,r=INF,nw;
char s[MAXN+10];
void U(int p,int k)
{
	if(k)
		for(int i=-4;i<=0;++i)
			l=max(l,a[p+i]+1);
	else
		for(int i=-4;i<=0;++i)
			r=min(r,a[p+i]-1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	scanf("%s",s+1);
	for(int i=5;i<=n;++i)
	{
		if(s[i]-'0'!=nw)
			U(i,nw=s[i]-'0');
	}
	printf("%d %d\n",l,r);
	return 0;
}