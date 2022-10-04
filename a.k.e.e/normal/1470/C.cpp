#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=100005;

int n,k;
inline int dmy(int i){return i<=0?i+n:(i>n?i-n:i);}
int ask(int x){printf("? %d\n",x);fflush(stdout);int y;readint(y);return y<k?-1:(y>k);}
/*int p,a[MAXN],b[MAXN];
int ask(int x)
{
	int y=a[x];
	for(int i=0;i<=n+1;++i)b[i]=0;
	for(int i=1;i<=n;++i)
	{
		if(i!=p)b[i-1]+=a[i]/2,b[i+1]+=(a[i]+1)/2;
		else b[i+1]+=a[i];
	}
	b[n]+=b[0],b[1]+=b[n+1];
	for(int i=1;i<=n;++i)a[i]=b[i];
	return y<k?-1:(y>k);
}*/

int main()
{
	#ifdef LOCAL
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(k);
	int l=1,r=n;
	int t=ask(n);
	for(int j=1;dmy(r-l+1)>j;++j)
	{
		if(j*2>=n)j-=1+(n&1);
		int t=ask(dmy(l-1));
		if(t<0)r=dmy(l+j-1);
		else l=dmy(l+j);
	}
	if(l>r)r+=n;
	while(l<r)
	{
		int m=(l+r)>>1;
		int t=ask(dmy(m));
		if(t<0)l=m+1;
		else if(t>0)r=m-1;
		else l=r=m;
	}
	printf("! %d\n",l);fflush(stdout);
	return 0;
}