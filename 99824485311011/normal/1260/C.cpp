#include<bits/stdc++.h>
using namespace std;
inline int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int T;
void solve()
{
	int p1,p2,K;
	scanf("%d%d%d",&p1,&p2,&K);
	if(K==1)
	{
		puts("REBEL");
		return;
	}
	int g=gcd(p1,p2);
	p1/=g;p2/=g;
	if(p1>p2)swap(p1,p2);
	if(p1==1)
	{
		if(p2==1)
		{
			puts("OBEY");
			return;
		}
		if(K<=p2-1)puts("REBEL");
		else puts("OBEY");
		return;
	}
	int mxcount=(p2-2)/p1+1;
	if(mxcount>=K)puts("REBEL");
	else puts("OBEY");
}
int main()
{
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}