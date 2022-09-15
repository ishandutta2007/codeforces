#include<cstdio>
#include<cstring>
int p[101010];
double ans[101010];
int sz[101010];
int N;
int main()
{
	scanf("%d", &N);
	for(int i=2; i<=N; i++)
		scanf("%d", p+i);
	p[1] = 0; ans[1] = 1.0;
	for(int i=1; i<=N; i++)
		sz[i] = 1;
	for(int i=N; i>=2; i--)
		sz[p[i]] += sz[i];
	for(int i=2; i<=N; i++)
		ans[i] = ans[p[i]]+(sz[p[i]]-sz[i] + 1.0)/2;
	for(int i=1; i<=N; i++)
		printf("%.12f ",ans[i]);
	
}