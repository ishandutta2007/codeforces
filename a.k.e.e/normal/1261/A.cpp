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
const int MAXN=2005;

int n,k;
char a[MAXN],b[MAXN];
void solve()
{
	readint(n);readint(k);scanf("%s",a+1);
	for(int i=1;i<=k-1;++i)b[i*2-1]='(',b[i*2]=')';
	for(int i=2*k-1;i<=k-1+n/2;++i)b[i]='(';
	for(int i=n/2+k;i<=n;++i)b[i]=')';
	printf("%d\n",n);
	for(int i=1;i<=n;++i)
	{
		int pos=i;
		for(int j=i;j<=n;++j)
			if(a[j]==b[i]){pos=j;break;}
		printf("%d %d\n",i,pos);
		for(int j=i;j<=(i+pos)/2;++j)
			swap(a[j],a[i+pos-j]);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}