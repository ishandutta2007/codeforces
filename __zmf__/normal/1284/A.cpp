//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,m,q,k,p,len1,len2;
int x[409],y[409];
char a[29][19],b[29][19]; 
int main()
{
	n=read(),m=read(),k=n*m;
	for(int i=1;i<=k;i++)x[i]=(i-1)%n+1,y[i]=(i-1)%m+1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	q=read();
	for(int i=1;i<=q;i++)
	{
		p=read();p=(p-1)%k+1;
		len1=strlen(a[x[p]]);
		len2=strlen(b[y[p]]);
		for(int j=0;j<len1;j++)putchar(a[x[p]][j]);
		for(int j=0;j<len2;j++)putchar(b[y[p]][j]);
		puts("");
	}
	return 0;
}