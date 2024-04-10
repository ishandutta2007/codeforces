#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 2100;
const int maxm = 210;
const int base = 29;
const int maxp = maxm;

int pwi[maxp];

int n,m;
int a[maxn][maxm],b[maxm][maxn];
int th[maxn],h1[maxn],h2[maxn];

char str[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	pwi[0]=1; for(int i=1;i<maxp;i++) pwi[i]=pwi[i-1]*base;
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++) a[i][j]=str[j]-'a'+1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=n;j++) b[i][j]=str[j]-'a'+1;
	}
	
	for(int i=1;i<=n;i++)
	{
		th[i]=0; int hc=base;
		for(int j=1;j<=m;j++) th[i]=th[i]*hc+a[i][j];
	}
	for(int i=1;i+m-1<=n;i++)
	{
		h1[i]=0; int hc=pwi[m];
		for(int j=1;j<=m;j++) h1[i]=h1[i]*hc+th[i+j-1];
	}
	
	for(int i=1;i<=n;i++)
	{
		th[i]=0; int hc=pwi[m];
		for(int j=1;j<=m;j++) th[i]=th[i]*hc+b[j][i];
	}
	for(int i=1;i+m-1<=n;i++)
	{
		h2[i]=0; int hc=base;
		for(int j=1;j<=m;j++) h2[i]=h2[i]*hc+th[i+j-1];
	}
	
	int ok=1;
	for(int i=1;i+m-1<=n&&ok;i++)
	{
		for(int j=1;j+m-1<=n&&ok;j++)
		{
			if(h1[i]==h2[j]) ok=0,printf("%d %d\n",i,j);
		}
	}
	
    return 0;
}