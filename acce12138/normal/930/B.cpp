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

char s[10111];
int n,cnt[26][50111];
vector<int> pos[26];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)s[i+n]=s[i];
	for(int i=1;i<=n;i++)pos[s[i]-'a'].pb(i);
	int ans=0;
	for(int i=0;i<26;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for(auto v:pos[i])for(int j=1;j<=n;j++)
			cnt[s[v+j-1]-'a'][j]++;
		int mx=0;
		for(int j=1;j<=n;j++)
		{
			int sum=0;for(int k=0;k<26;k++)sum+=(cnt[k][j]==1);
			mx=max(mx,sum);
		}
		ans+=mx;
	}
	printf("%.10lf\n",ans*1.0/n);
	return 0;
}