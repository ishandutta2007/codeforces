#include<bits/stdc++.h>
using namespace std;
int n,k,l;
char s[100002];
int pre[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int check(int x)
{
	for(int i=x;i<=l;++i)
		if(pre[i]-pre[i-x]<=k || i-pre[i]-((i-x)-pre[i-x])<=k)
			return 1;
	return 0;
}
inline int binary_search(int l,int r)
{
	int mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	read(n),read(k),scanf("%s",s+1),l=strlen(s+1);
	for(int i=1;i<=l;++i)pre[i]=pre[i-1]+(s[i]=='a');
	printf("%d",binary_search(2,l));
	return 0;
}