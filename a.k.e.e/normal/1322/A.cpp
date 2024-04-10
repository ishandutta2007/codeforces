#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=1000005;

int n,a[MAXN];
char str[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	scanf("%s",str+1);
	int sum=0;
	for(int i=1;i<=n;++i)a[i]=(str[i]=='('?1:-1),sum+=a[i];
	if(sum)return 0*printf("-1\n");
	int las=0,ans=0;
	bool flag=0;
	for(int i=1;i<=n;++i)
	{
		a[i]+=a[i-1];
		if(a[i]==0)
		{
			if(flag)ans+=i-las;
			las=i,flag=0;
		}
		else if(a[i]<0)flag=1;
	}
	cout<<ans<<endl;
	return 0;
}