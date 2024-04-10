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
#include<cstdlib>
void ask(int _id)
{printf("+ %d\n",_id),ouf();}
int rd()
{int x;scanf("%d",&x);return x;}
#include<cmath>
int rev(int x)
{return sqrt(x<<1);}
int c[11111],x[11111];
void answ()
{
	printf("! "),c[1]++;
	register int i;
	for(i=1;i<=n;i++)printf("%d ",c[i]);
	puts(""),ouf(),exit(0);
}
int a[111111],b[111111],dx[111111];
int main(int argc,char*argv[])
{
	srand((unsigned ll)(new int*));
	scanf("%d",&n);
	int ls,tp,lf,tf;
	register int i;
	a[0]=rd(),b[0]=rd();
	for(i=2;i<=n-2;i++)ask(i),a[i-1]=rd(),b[i-1]=rd(),dx[i]=b[i-1]-b[i-2];
	ask(n),a[n-2]=rd(),b[n-2]=rd(),dx[n-1]=b[n-2]-b[n-3];
	ask(n-1),a[n-1]=rd(),b[n-1]=rd(),dx[n]=b[n-1]-b[n-2];
	ask(n),a[n]=rd(),b[n]=rd(),dx[n+1]=b[n]-b[n-1];
	c[n]=rev(a[n]-a[n-1]);
	c[n-2]=(dx[n+1]-dx[n-1])-1;
	c[n-1]=dx[n+1]/(c[n-2]+1)-1;
	c[n-3]=(dx[n]-(c[n-2]+1)*(c[n]+1))/(c[n-2]+1)-1;
	for(i=n-4;i>=1;i--)
		c[i]=(dx[i+2]-(c[i+1]+1)*c[i+3]-c[i+4]*c[i+3])/(c[i+1]+1)-1;
	answ();
}