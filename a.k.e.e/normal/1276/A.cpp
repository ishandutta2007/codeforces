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
const int MAXN=150005;

int n,a[MAXN];
char s[MAXN];
bool c21(const char *s){return s[0]=='t' && s[1]=='w' && s[2]=='o' && s[3]=='n' && s[4]=='e';}
bool c2(const char *s){return s[0]=='t' && s[1]=='w' && s[2]=='o';}
bool c1(const char *s){return s[0]=='o' && s[1]=='n' && s[2]=='e';}
void solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int i=1,ans=0;
	while(i<=n)
	{
		if(c21(s+i))a[++ans]=i+2,i+=3;
		else if(c1(s+i) || c2(s+i))a[++ans]=i+1,i+=2;
		else ++i;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)printf("%d ",a[i]);
	putchar('\n');
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}