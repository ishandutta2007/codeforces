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
//const int N=109;
int n,k,taxi;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read(),k=read();
		if(k%3==0&&n>=k)
		{
			n=n%(k+1);
			if(n==k)puts("Alice");
			else if(n%3==0)puts("Bob");
			else puts("Alice");
		}
		else
		{
			if(n%3==0)puts("Bob");
			else puts("Alice");
		}
	}
	return 0;
}