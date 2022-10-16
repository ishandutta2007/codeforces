#include<bits/stdc++.h>

bool f[1111111];
std::vector<int>divs[1111111];
void init()
{
	
	register int i,ii;
	int n=1000;
	for(i=2;i<=n;i++)
		for(ii=i<<1;ii<=n;ii+=i)
			divs[ii].push_back(i);
	for(i=2;i<=n;i++)
	{
		for(int t:divs[i])if(!f[i-t])f[i]=1;
		printf("%d %d\n",i,(int)f[i]);
	}
	
}

void exec()
{
	int n;
	scanf("%d",&n);
	if(n&1)
	{
		puts("Bob");
	}
	else
	{
		while(n%4==0)n/=4;
		if(n==2)puts("Bob");
		else puts("Alice");
	}
}

int main()
{
	//init();
	int T;
	scanf("%d",&T);
	while(T--)exec();
}