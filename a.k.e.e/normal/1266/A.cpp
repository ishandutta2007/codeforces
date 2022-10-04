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
const int MAXN=100005;

int n;
char s[MAXN];
void solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int f0=0,f2=0;
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		int x=s[i]-'0';
		if(!x)++f0;
		if(!(x&1))++f2;
		sum+=x;
	}
	sum%=3;
	printf((!sum && f0 && f2>=2)?"red\n":"cyan\n");
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