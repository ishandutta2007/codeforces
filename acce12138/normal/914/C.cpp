// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
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
char s[1111];
int k,n,c[1111][1111],sum[1111],dp[1111];
int main()
{
	for(int i=0;i<1111;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			if(c[i][j]>=mod)c[i][j]-=mod;
		}
	}
	scanf("%s%d",s+1,&k);n=strlen(s+1);
	if(k==0)
	{
		puts("1");
		return 0;
	}
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			for(int j=0;j<=n-i;j++)
				sum[cur+j]=(sum[cur+j]+c[n-i][j])%mod;
			cur++;
		}
	}
	sum[cur]++;if(sum[cur]>=mod)sum[cur]-=mod;sum[1]--;if(sum[1]<0)sum[1]+=mod;
	for(int i=2;i<1111;i++)dp[i]=dp[__builtin_popcount(i)]+1;
	int ans=0;
	for(int i=1;i<1111;i++)if(dp[i]==k-1)ans=(ans+sum[i])%mod;
	printendl(ans);
	return 0;
}