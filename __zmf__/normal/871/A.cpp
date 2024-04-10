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
int taxi,n;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		if(n%4==0)
		{
			cout<<n/4<<endl;
		}
		else if(n%4==1)
		{
			if(n<=5)cout<<-1<<endl;
			else cout<<(n-9)/4+1<<endl;
		}
		else if(n%4==2)
		{
			if(n<=2)cout<<-1<<endl;
			else cout<<(n-6)/4+1<<endl;
		}
		else
		{
			if(n<=11)cout<<-1<<endl;
			else cout<<(n-15)/4+2<<endl;
		}
	}
	return 0;
}