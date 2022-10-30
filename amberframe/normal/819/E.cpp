#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;
typedef long long LL;

const int maxn = 900005;
struct node {
	int o,a,b,c,d;
}p[maxn];int tot,n,w;
void add3(int a,int b,int c)
{
	p[++tot]=(node){3,a,b,c,0};
	p[++tot]=(node){3,a,b,c,0};
}
void add4(int a,int b,int c,int d)
{
	p[++tot]=(node){3,a,b,d,0};
	p[++tot]=(node){3,c,b,d,0};
	p[++tot]=(node){3,a,b,c,0};
	p[++tot]=(node){3,a,c,d,0};
}
void add5()
{
	p[++tot]=(node){3,5,4,2,0};
	p[++tot]=(node){3,3,1,5,0};
	p[++tot]=(node){4,4,5,2,3};
	p[++tot]=(node){4,4,3,2,1};
	p[++tot]=(node){3,4,2,1,0};
	p[++tot]=(node){3,3,1,5,0};
}
void add(int a,int b,int c)
{
	for (int i=1;i+1<=n;i+=2)
	{
		int j=i+1;
		p[++tot]=(node){4,a,i,b,j};
		p[++tot]=(node){4,a,i,c,j};
		p[++tot]=(node){4,b,i,c,j};
	}
	if (n&1) add4(a,b,c,n);
	else add3(a,b,c);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("moon.in","r",stdin);
		freopen("moon.out","w",stdout);
	#endif
	scanf("%d",&w);
	if (w%3==0) add3(1,2,3),n=3;
	else if (w%3==1) add4(1,2,3,4),n=4;
	else if (w%3==2) add5(),n=5;
	while (n<w) {
		add(n+1,n+2,n+3);n+=3;
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++)
	if (p[i].o==3) printf("%d %d %d %d\n",3,p[i].a,p[i].b,p[i].c);
	else  printf("%d %d %d %d %d\n",4,p[i].a,p[i].b,p[i].c,p[i].d);
	return 0;
}