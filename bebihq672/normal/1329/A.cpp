#include<bits/stdc++.h>
using namespace std;

struct Oper{
	int len,num;
}a[101010];

bool cmp(const Oper &A,const Oper &B)
{
	return A.len>B.len;
}

int ans[101010];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	
	long long sum=0;
	
	for(int i=1;i<=M;i++)
	{
		int x;
		scanf("%d",&x);
		a[i].len=x;
		sum+=x;
		a[i].num=i;
	}
	
	//sort(a+1,a+N+1,cmp);
	a[0].len=1;
	int last=0;
	for(int i=1;i<=M;i++)
	{
		int tmp=max(last+1ll,N-sum+1);
		if(tmp<=last||last+a[i-1].len<tmp||tmp+a[i].len-1>N)
		{
			puts("-1");
			return 0;
		}
		sum-=a[i].len; 
		ans[a[i].num]=tmp;
		last=tmp;
	}
	for(int i=1;i<=M;i++)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}