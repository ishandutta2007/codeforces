//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,sum;
char a[109];
int main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++)
		sum+=(a[i]-'0');
	if(sum==1||n==1)
	{
		cout<<n/2<<endl;
	}
	else cout<<(n+1)/2<<endl;
	return 0;
}