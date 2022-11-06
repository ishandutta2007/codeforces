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
int n,k,cnt;
char a[100009];
int main()
{
	n=read(),k=read();
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<i;j++)a[cnt++]=j+'a',a[cnt++]=i+'a';
		a[cnt++]=i+'a';
	}
	for(int i=0;i<n;i++)putchar(a[i%cnt]);
	puts("");
	return 0;
}