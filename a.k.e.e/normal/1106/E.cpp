#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int MAXN=100005,MAXM=205;
const ll INF=0x3f3f3f3f3f3f3f3fll;

int n,m;
struct Data
{
	int l,r,d,w;
	inline bool operator <(const Data &b)const
		{return w==b.w?d>b.d:w>b.w;}
	inline bool operator >(const Data &b)const
		{return b<*this;}
}a[MAXN];
inline bool cmpl(Data a,Data b){return a.l<b.l;}
priority_queue<Data,vector<Data>,greater<Data> > pq;
int d[MAXN],w[MAXN];
ll f[MAXN][MAXM];
inline void chkmin(ll &x,ll y){x>y?(x=y):0;}

int main()
{
    int q;
    scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d%d%d",&a[i].l,&a[i].r,&a[i].d,&a[i].w);
	sort(a+1,a+q+1,cmpl);
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		while(cur<q && a[cur+1].l<=i)pq.push(a[++cur]);
		while(!pq.empty() && pq.top().r<i)pq.pop();
		if(!pq.empty())
		{
			Data tmp=pq.top();
			d[i]=tmp.d;w[i]=tmp.w;
		}
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			chkmin(f[i+1][j+1],f[i][j]);
			if(d[i])chkmin(f[d[i]+1][j],f[i][j]+w[i]);
			else chkmin(f[i+1][j],f[i][j]);
		}
	ll ans=INF;
	for(int j=0;j<=m;j++)
		chkmin(ans,f[n+1][j]);
	cout<<ans<<endl;
    return 0;
}