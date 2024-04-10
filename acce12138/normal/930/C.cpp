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

int n,m,l[100111],r[100111],pre[100111],v1[100111],v2[100111];

int bit[100111];
void modify(int x,int v){for(;x<100111;x+=x&-x)bit[x]=max(bit[x],v);}
int query(int x){int ret=0;for(;x;x-=x&-x)ret=max(ret,bit[x]);return ret;}

int main()
{
	get2(n,m);
	if(m==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		get2(l[i],r[i]);
		pre[l[i]]++;
		pre[r[i]+1]--;
	}
	pre[0]=1;
	for(int i=1;i<=m;i++)pre[i]+=pre[i-1];
	
	for(int i=1;i<=m;i++)
	{
		v1[i]=query(pre[i])+1;
		modify(pre[i],v1[i]);
	}
	memset(bit,0,sizeof(bit));
	int ans=0;
	for(int i=m;i>=1;i--)
	{
		v2[i]=query(pre[i])+1;
		modify(pre[i],v2[i]);
		ans=max(ans,v1[i]+v2[i]-1);
	}
	printendl(ans);
	return 0;
}