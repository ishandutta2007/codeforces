#include<bits/stdc++.h>
#define retrun return
#define cpnst const
typedef long long ll;
typedef double db;
typedef unsigned unt;
typedef unsigned long long ull;
using std::sort;
using std::min;
using std::max;
using std::swap;
using std::reverse;
struct pii{int x,y;};
bool operator<(const pii x,const pii y){return x.x^y.x?x.x<y.x:x.y<y.y;}
ll gcd(ll x,ll y){for(ll r=y;r;r=x%y,x=y,y=r);return x;}
int n,m,q;
char str[1111111];
int a[1111111],b[1111111];
int f[2][103][10303];
int S=0;
void exec()
{
	scanf("%d",&n);
	register int i,ii,iii;
	for(i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	for(i=1;i<=n;i++)S+=b[i];
	for(ii=0;ii<=n;ii++)for(iii=0;iii<=10100;iii++)f[0][ii][iii]=f[1][ii][iii]=-1e8;
	f[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		int V=100*i,cr=i&1,pr=cr^1;
		for(ii=0;ii<=i;ii++)for(iii=0;iii<=100*(i+1);iii++)f[cr][ii][iii]=-1e8;
		for(ii=0;ii<i;ii++)
		{
			for(iii=0;iii<=V;iii++)
			{
				if(f[pr][ii][iii]+b[i]>f[cr][ii+1][iii+a[i]])
					f[cr][ii+1][iii+a[i]]=f[pr][ii][iii]+b[i];
				if(f[pr][ii][iii]>f[cr][ii][iii])
					f[cr][ii][iii]=f[pr][ii][iii];
			}
		}
	}//printf("%d\n",f[n&1][2][24]);
	for(ii=1;ii<=n;ii++)
	{
		int ANS=0;
		for(iii=0;iii<=100*n;iii++)
		{
			int res=S-f[n&1][ii][iii];
			if(min(res+f[n&1][ii][iii]*2,iii*2)>ANS)
			{
				ANS=min(res+f[n&1][ii][iii]*2,iii*2);
				//printf("%d %d\n",iii,ANS);
			}
		}printf("%d.%d ",ANS>>1,(ANS&1)?5:0);
	}puts("");
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}