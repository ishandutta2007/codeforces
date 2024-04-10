#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,q,sq,tot,las,Lst_t=0,Rst_t=0;
int pre[200002],pre1[200002][2];
char s[200002];
struct aaa
{
	int l,r,id;
};
vector<aaa> vec[452];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(q),scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0' && s[i-1]!='0')
		{
			pre1[i][0]=1;
		}
		if(s[i]=='1' && s[i-1]!='1')
		{
			pre1[i][1]=1;
		}
		pre1[i][0]+=pre1[i-1][0];
		pre1[i][1]+=pre1[i-1][1];
	}
	for(int i=1;i<=n;++i)
	{
		pre[i]=pre[i-1]+(s[i]=='0');
	}
	for(int l,r;q--;)
	{
		scanf("%d%d",&l,&r);
		
		printf("%d\n",max(pre[r]-pre[l-1]-(pre1[r][0]-pre1[l-1][0]+(s[l]=='0' && s[l-1]=='0')),
		(r-l+1)-(pre[r]-pre[l-1])-(pre1[r][1]-pre1[l-1][1]+(s[l]=='1' && s[l-1]=='1')))+1);
	}
	return 0;
}