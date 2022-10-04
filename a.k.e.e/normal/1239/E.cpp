#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
void readint(int &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
void readint(ll &x)
{
	x=0;ll f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
inline void chkmin(int &x,int y){x>y?x=y:0;}
inline void chkmin(ll &x,ll y){x>y?x=y:0;}
inline void chkmax(int &x,int y){x<y?x=y:0;}
const int MAXN=51;

int n,a[MAXN],sum=0;
int f[MAXN][MAXN*25000+1];
bool cho[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);
	enum(i,1,2*n)readint(a[i]);
	sort(a+1,a+2*n+1);
	enum(i,3,2*n)sum+=a[i];
	f[0][0]=-1;
	enum(i,3,2*n)
		try(j,min(i-1,n-1),1)
			enum(k,a[i],sum>>1)
				if(f[j-1][k-a[i]] && !f[j][k])f[j][k]=i;
	int cur=n-1,pos=0;
	try(k,sum>>1,0)
		if(f[n-1][k]){pos=k;break;}
	while(cur)
	{
		int t=f[cur--][pos];
		cho[t]=1;pos-=a[t];
	}
	printf("%d ",a[1]);enum(i,3,2*n)if(cho[i])printf("%d ",a[i]);printf("\n");
	try(i,2*n,3)if(!cho[i])printf("%d ",a[i]);printf("%d ",a[2]);
	return 0;
}