#include<bits/stdc++.h>
const int maxn=1<<20;
int n,m,k;
char s[1<<20];
int a[1<<20];
int b[1<<20];
int c[1<<20];
int ask(int p)
{
	printf("? %d\n",p);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	return t;
}
bool decided[1<<20];
int p[1<<20];
void solve_Loop(int x)
{
	int P=x;
	std::vector<int>v;
	int S=ask(P);x=S;
	v.push_back(S);
	decided[S]=1;
	for(;;)
	{
		int t=ask(P);
		v.push_back(t);
		if(t==S)break;
		decided[t]=1;
	}
	for(int i=0;i<v.size()-1;i++)
	{
		p[v[i]]=v[i+1];
	}
}
void exec()
{
	scanf("%d",&n);
	if(n==1)
	{
		puts("! 1");
		fflush(stdout);
		return;
	}
	for(int i=1;i<=n;i++)decided[i]=p[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(!decided[i])
		{
			if(i!=n)solve_Loop(i);
			else p[i]=n;
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	puts("");
	fflush(stdout);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}