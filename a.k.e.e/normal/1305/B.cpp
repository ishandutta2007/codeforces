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
const int MAXN=1005;

int n,m;
char s[MAXN];
bool sel[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int x=1,y=n;x<=y;++x,--y)
	{
		while(x<=n && s[x]!='(')++x;
		while(y && s[y]!=')')--y;
		if(x>y)break;
		sel[x]=sel[y]=1;
		m+=2;
	}
	if(!m)return 0*printf("0\n");
	printf("1\n%d\n",m);
	for(int i=1;i<=n;++i)if(sel[i])printf("%d ",i);
	return 0;
}