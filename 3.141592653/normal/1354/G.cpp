#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cstring>
#include<random>
#define errlog(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
std::mt19937 Rand((unsigned ll)(new int*));
inline ull Ranll()
{return(Rand()*(1llu<<32llu))+(Rand());}
inline ll random(ll l,ll r)
{return Ranll()%(r-l+1)+l;}
int n;
#define ouf() fflush(stdout)
void ask(int L1,int R1,int L2,int R2)
{
	printf("? %d %d\n",R1-L1+1,R2-L2+1);
	register int i;
	for(i=L1;i<=R1;i++)printf("%d ",i);puts("");
	for(i=L2;i<=R2;i++)printf("%d ",i);puts("");
	printf("\n");
	ouf();
}
void ask(int R){ask(1,1,R,R);}
#include<cstdlib>
int answer()
{
	char tmp[11];
	scanf("%s",tmp);
	if(*tmp=='W')exit(0);
	if(*tmp=='F')return 1;
	if(*tmp=='S')return 2;
	if(*tmp=='E')return 0;
	return -1;
}
void solve(int l,int r)
{
	if(r>n)r=n;
	if(l==r)return printf("! %d\n",l),ouf(),void();
	int mid=(l+r)>>1;
	ask(1,mid-l+1,l,mid);
	if(answer()==1)solve(l,mid);
	else solve(mid+1,r);
}
void exec()
{
	scanf("%d%*d",&n);
	register int i;
	for(i=1;i<=25;i++)
	{
		ask(random(2,n));
		if(answer()==2)return puts("! 1"),ouf(),void();
	}
	int r=2;
	for(;;r<<=1)
	{
		if(r>n)break;
		ask(1,r>>1,(r>>1)+1,r);
		if(answer()==1)break;
	}solve((r>>1)+1,r);
}
int main(int argc,char*argv[])
{
	srand((unsigned ll)(new int*));
	int T;
	scanf("%d",&T);
	while(T--)exec();
}