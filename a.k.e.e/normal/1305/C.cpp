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
const int MAXN=200005,MAXM=1005;

int n,m,a[MAXN],b[MAXM];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=n;++i)readint(a[i]),++b[a[i]%m];
	for(int j=0;j<m;++j)
		if(b[j]>=2)return 0*printf("0\n");
	ll ans=1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			ans=ans*abs(a[i]-a[j])%m;
	cout<<ans<<endl;
	return 0;
}