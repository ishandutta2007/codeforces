#include<bits/stdc++.h>
using namespace std;
int la,lb;
int A[200002],t[200002];
char a[200002],b[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(int x)
{
	int j=1;
	for(int i=1;i<=la && j<=lb;++i)if(t[i]>x)j+=(a[i]==b[j]);
	return j>lb? 1:0;
}
inline int binary_search()
{
	int l=1,r=la,mid;
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
	scanf("%s%s",a+1,b+1),la=strlen(a+1),lb=strlen(b+1);
	for(int i=1;i<=la;++i)scanf("%d",&A[i]),t[A[i]]=i;
	return 0&printf("%d",binary_search());
}