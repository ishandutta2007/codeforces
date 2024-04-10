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
int n,taxi,l,r,cnt;
char a[100009];
int main()
{
	cin>>taxi;
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		cnt=0;
		n=read();
		cin>>a;
		l=0,r=n-1;
		while(a[l]=='0')l++;
		//cout<<l<<endl;
		for(int i=1;i<=l;i++)putchar('0');
		while(a[r]=='1')r--;
		if(l-r!=1)putchar('0');
		cnt=n-1-r;
		for(int i=1;i<=cnt;i++)putchar('1');
		puts("");
	}
	return 0;
}