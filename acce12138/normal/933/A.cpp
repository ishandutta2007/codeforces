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

int n,a[2333],dpl[2333][2],dpr[2333][2],dpt[2333][2333][2][2];
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		a[i]--;
	}
	for(int i=1;i<=n;i++)
	{
		dpl[i][0]=dpl[i-1][0];
		dpl[i][1]=dpl[i-1][1];
		for(int j=0;j<=a[i];j++)dpl[i][a[i]]=max(dpl[i][a[i]],dpl[i-1][j]+1);
	}
	for(int i=n;i>=1;i--)
	{
		dpr[i][0]=dpr[i+1][0];
		dpr[i][1]=dpr[i+1][1];
		for(int j=a[i];j<2;j++)dpr[i][a[i]]=max(dpr[i][a[i]],dpr[i+1][j]+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			memcpy(dpt[i][j],dpt[i][j-1],sizeof(dpt[i][j]));
			dpt[i][j][a[j]][a[j]]=1;
			for(int k=1;k>=a[j];k--)for(int k2=a[j];k2<=k;k2++)
				dpt[i][j][k][a[j]]=max(dpt[i][j][k][a[j]],dpt[i][j-1][k][k2]+1);
			for(int k=0;k<2;k++)for(int k2=0;k2<=k;k2++)
				ans=max(ans,dpt[i][j][k][k2]+dpl[i-1][k2]+dpr[j+1][k]);
		}
	}
	printendl(ans);
	return 0;
}