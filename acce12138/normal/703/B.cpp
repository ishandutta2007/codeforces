//  This code is written by Eric Sunli Chen ( OhWeOnFire ).
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T>
void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T>
void print_int(T x)
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,k,cap,c[100111],id[100111],cap2;
bool ok[100111];
LL ans,ans2;
int main()
{
	get2(n,k);
	for(int i=1;i<=n;i++)
	{
		get1(c[i]);
		cap+=c[i];
	}
	for(int i=1;i<=k;i++)
	{
		get1(id[i]);
		ok[id[i]]=1;
		cap2+=c[id[i]];
	}
	for(int i=1;i<=k;i++)
	{
		ans+=(cap-c[id[i]])*1ll*c[id[i]];
		ans2+=(cap2-c[id[i]])*1ll*c[id[i]];
	}
	for(int i=1;i<=n;i++)
	{
		int j=i+1;if(j>n)j-=n;
		if(ok[i]|ok[j])continue;
		ans+=c[i]*c[j];
	}
	printendl(ans-ans2/2);
	return 0;
}