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
int n;
char a[109];
int main()
{
	n=read();cin>>a;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			int kk=i;
			for(int j=1;j<=kk/2;j++)swap(a[j-1],a[kk-j]);
		}
	}
	cout<<a<<endl;
	return 0;
}