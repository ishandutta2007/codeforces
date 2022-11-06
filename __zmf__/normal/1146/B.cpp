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
const int N=1e5+9;
int n,k,cnt;
char a[N],b[N];
int main()
{
	cin>>a;
	n=strlen(a);
	for(int i=0;i<n;i++)
		if(a[i]!='a')k++;
	if(k%2==1)
	{
		puts(":(");
		return 0;
	}
	k=k/2;
	for(int i=0;i<n-k;i++)
		if(a[i]!='a')b[cnt++]=a[i];
	for(int i=0;i<cnt;i++)
		if(a[n-i-1]!=b[(cnt-1)-i])
		{
			puts(":(");
			return 0;
		}
	for(int i=0;i<n-k;i++)putchar(a[i]);
	return 0;
}