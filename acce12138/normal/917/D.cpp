// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;
int power(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}

int eu[111],ev[111],n,con[111][111],v[111];

int a[111][111];
int det()
{
//	for(int i=1;i<n;i++)for(int j=1;j<n;j++)printf("%d%c",a[i][j],j==n-1?'\n':' ');
	int coef=1;
	for(int i=1;i<n;i++)
	{
		if(!a[i][i])
		{
			for(int j=i+1;j<n;j++)if(a[j][i])
			{
				for(int k=1;k<n;k++)swap(a[i][k],a[j][k]);
				coef=mod-coef;break;
			}
		}
		if(!a[i][i])return 0;
		coef=1ll*coef*a[i][i]%mod;int rev=power(a[i][i],mod-2);
		for(int j=1;j<n;j++)a[i][j]=1ll*a[i][j]*rev%mod;
		for(int j=i+1;j<n;j++)
		{
			int tmp=a[j][i];
			for(int k=1;k<n;k++)a[j][k]=(a[j][k]-1ll*tmp*a[i][k]%mod+mod)%mod;
		}
	}
	return coef;
}
int matrix_tree()
{
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		a[i][i]+=con[i][j];
		if(con[i][j])a[i][j]=mod-con[i][j];
	}
	return det();
}

int main()
{
	get1(n);
	for(int i=1;i<n;i++)get2(eu[i],ev[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)con[j][k]=(j!=k);
		for(int j=1;j<n;j++)con[eu[j]][ev[j]]=con[ev[j]][eu[j]]=i;
		v[i]=matrix_tree();
	}
	for(int i=1;i<=n;i++)
	{
		a[i][1]=1;for(int j=2;j<=n;j++)a[i][j]=1ll*a[i][j-1]*i%mod;
		a[i][n+1]=v[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)if(a[j][i])
		{
			for(int k=1;k<=n+1;k++)swap(a[i][k],a[j][k]);
			break;
		}
		int rev=power(a[i][i],mod-2);
		for(int j=1;j<=n+1;j++)a[i][j]=1ll*a[i][j]*rev%mod;
		for(int j=1;j<=n;j++)if(i!=j)
		{
			int tmp=a[j][i];
			for(int k=1;k<=n+1;k++)
				a[j][k]=(a[j][k]-1ll*tmp*a[i][k]%mod+mod)%mod;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i][n+1]);
	return 0;
}