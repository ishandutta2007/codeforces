#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
void readint(int &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
inline void chkmin(int &x,int y){x>y?x=y:0;}
inline void chkmax(int &x,int y){x<y?x=y:0;}
const int MAXN=1000005,MOD=998244353;

int n;
ll f[2][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);
	int cur=1,flg=0;
	while(cur<=n)
	{
		if(n==cur || n==cur+1)return 0*printf("1\n");
		if(!flg)cur=cur*2+2;
		else cur=cur*2+1;
		flg^=1;
	}
	printf("0\n");
	/*f[0][0]=f[1][0]=1;
	f[0][1]=0;f[1][1]=1;
	enum(i,2,n)
	{
		int k=0;
		while((1<<k)<=i)++k;
		if(i==(1<<k)-1){f[0][i]=f[1][i]=0;continue;}
		--k;
		enum(j,max((1<<(k-1))-1,i-(1<<k)),min((1<<k)-1,i-(1<<(k-1))))
			f[(j+1)&1][i]+=f[j&1][j]*f[0][i-j-1];
	}
	enum(i,1,n)if(f[0][i]+f[1][i]==1)printf("%d ",i);*/
	return 0;
}