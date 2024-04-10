#include<cstdio>
#define MOD 1000000007
const int BIAS=101010;
int ufd[202020];
bool vis[202020];
int Find(int a)
{
	if(a==ufd[a]) return a;
	else return ufd[a]=Find(ufd[a]);
}
void Union(int a,int b)
{
	ufd[Find(a)]=Find(b);
}
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<2*BIAS;i++) ufd[i]=i;
	for(int i=0;i<K;i++)
	{
		int a,b;
		char c;
		scanf("%d%d %c",&a,&b,&c);
		a--; b--;
		if(a>b) a^=b^=a^=b;
		if(a+b>=N)
		{
			int t=b; b=a; a=t;
			a=N-1-a; b=N-1-b;
		}
		//printf("%d %d\n",a,b);
		a++; b++;
		int X=b-a,Y=b+a;
		if(X==0) X=1;
		//printf("%d %d\n",X,Y);
		if(c=='x')
		{
			Union(X,Y);
			Union(BIAS+X,BIAS+Y);
		}
		else
		{
			Union(BIAS+Y,X);
			Union(BIAS+X,Y);
		}
		//printf("%d %d\n",X,Y);
	}
	
	for(int i=1;i<N+2;i++)
		if(Find(BIAS+i)==Find(i))
		{
			puts("0");
			return 0;
		}
	int cnt=-1;
	for(int i=1;i<N+2;i++)
	{
		if(!vis[Find(i)])
		{
			vis[Find(i)]=true;
			cnt++;
		}
	}
	for(int i=2+BIAS;i<BIAS+N+2;i++)
	{
		if(!vis[Find(i)])
		{
			vis[Find(i)]=true;
			cnt++;
		}
	}
	cnt/=2;
	int ans=1;
	for(int i=0;i<cnt;i++) ans=(ans*2)%1000000007;
	printf("%d",ans);
}