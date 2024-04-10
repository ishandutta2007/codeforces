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
const int MAXN=305;

int n,m,a[MAXN],b[MAXN],p[MAXN],l[MAXN],r[MAXN],f[MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		readint(a[i]),readint(b[i]);
		p[i*3-2]=a[i]-b[i],p[i*3-1]=a[i],p[i*3]=a[i]+b[i];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<n;++j)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]),swap(b[j],b[j+1]);
	sort(p+1,p+3*n+1);
	m=unique(p+1,p+3*n+1)-p-1;
	for(int i=1;i<=n;++i)
	{
		l[i]=lower_bound(p+1,p+m+1,a[i]-b[i])-p;
		r[i]=lower_bound(p+1,p+m+1,a[i]+b[i])-p;
		a[i]=lower_bound(p+1,p+m+1,a[i])-p;
	}
//for(int i=1;i<=m;++i)cerr<<p[i]<<" ";cerr<<endl;
//for(int i=1;i<=n;++i)cerr<<l[i]<<" "<<a[i]<<" "<<r[i]<<endl;
	for(int i=1;i<=n;++i)
//{
		for(int j=1;j<=m;++j)
		{
			for(int k=1;k<=i;++k)
			{
				if(r[k]<j || l[k]>j)continue;
				if(a[k]>=j)
				{
					int cur=l[k];
					for(int t=k+1;t<=i;++t)chkmin(cur,l[t]);
					chkmax(f[i][j],f[k-1][cur]+p[j]-p[cur]);
				}
				else
				{
					int cur=a[k];
					for(int t=k+1;t<=i;++t)chkmin(cur,l[t]);
					chkmax(f[i][j],f[k-1][cur]+p[j]-p[cur]);
				}
			}
			chkmax(f[i][j],f[i][j-1]);
//cerr<<f[i][j]<<" ";
		}
//cerr<<endl;}
	printf("%d\n",f[n][m]);
	return 0;
}