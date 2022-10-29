#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t,p1,p2,K;
void Read(int &x)
{
	char c;
	while((c=getchar())<'0'||c>'9');
	x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
}
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
	Read(t);
	while(t--)
	{
		Read(p1);Read(p2);Read(K);
		if(K==1)
		{
			puts("REBEL");
			continue;
		}
		if(p1==p2)
		{
			puts("OBEY");
			continue;
		}
		if(p1>p2)
			swap(p1,p2);
		if(1+(p2-gcd(p1,p2)-1)/p1<K)
			puts("OBEY");
		else
			puts("REBEL");
	}
	return 0;
}