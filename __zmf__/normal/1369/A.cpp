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
int taxi,n;
int main()
{
	cin>>taxi;
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		if(n%4==0)puts("YES");
		else puts("NO");
	}
	return 0;
}