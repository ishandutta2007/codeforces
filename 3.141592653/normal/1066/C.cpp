#include<cstdio>
#include<algorithm>
typedef long long ll;
struct pii
{int x,Id;};
inline bool operator<(const pii x,const pii y)
{return x.x<y.x;}
#include<set>
std::set<pii>s;
char str[11];
int p[222222];
int v,l=0,r=0;
inline int min(int x,int y)
{return(x>y)?y:x;}
bool v0;
void exec()
{
	int n;
	scanf("%s%d",str,&n);
	if(*str=='?')
	{
		printf("%d\n",min(p[n]-l,r-p[n]));
	}if(*str=='L')
	{
		if(!v0)p[n]=0,v0=1;
		else p[n]=(--l);
	}if(*str=='R')
	{
		if(!v0)p[n]=0,v0=1;
		else p[n]=(++r);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	//T=1;
	while(T--)exec();
}