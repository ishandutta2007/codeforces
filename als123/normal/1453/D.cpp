#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
vector<LL> vec;
int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		LL k;
		scanf("%lld",&k);
		if (k&1) {printf("-1\n");continue;}
		LL t=2,t1=0,sum=0;vec.clear();
		while (true)	{if (t1+t>k) break;t1=t1+t;sum++;t<<=1;}
		t>>=1;
		while (k!=0)
		{
			while (k>=t1) 	{vec.push_back(sum);k-=t1;}
			t1=t1-t;t>>=1;sum--;
		}
		LL siz=vec.size();
		LL n=0;
		for (LL u=0;u<siz;u++)	n=n+vec[u];
		if (n>2000) {printf("-1\n");continue;}
		printf("%lld\n",n);
		for (LL u=0;u<siz;u++)
		{
			LL siz=vec[u];
			printf("1 ");
			for (LL i=0;i<siz-1;i++) printf("0 ");
		}
		printf("\n");
	}
	return 0;
}