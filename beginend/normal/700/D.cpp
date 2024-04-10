#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>

typedef long long LL;

const int N=100005;

int n,m,B,bel[N],a[N],t[N],c[N],d[N];
LL ans[N];
struct data{int l,r,id;}q[N];
std::priority_queue<int> que;
std::vector<int> vec;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool cmp(data a,data b)
{
	return bel[a.l]<bel[b.l]||bel[a.l]==bel[b.l]&&((bel[a.l]&1)?(a.r<b.r):(a.r>b.r));
}

void updata(int x,int y)
{
	if (t[a[x]]<=B) d[t[a[x]]]--;
	t[a[x]]+=y;
	if (t[a[x]]<=B) d[t[a[x]]]++;
}

LL query()
{
	int p1=1,p2=1;LL ans=0;
	for (int i=0;i<vec.size();i++)
		if (t[vec[i]]>B) que.push(-t[vec[i]]);
	for (int i=1;i<=B;i++) c[i]=d[i];
	while (p1<=B)
	{
		while (p1<=B&&!c[p1]) p1++;
		while (p2<=B&&(!c[p2]||c[p2]==1&&p1==p2)) p2++;
		if (p1>B||p2>B) break;
		int s=(p1==p2)?c[p1]/2:std::min(c[p1],c[p2]);
		ans+=(LL)(p1+p2)*s;
		c[p1]-=s;c[p2]-=s;
		if (p1+p2>B) for (int i=1;i<=s;i++) que.push(-p1-p2);
		else c[p1+p2]+=s;
	}
	if (c[p1]) que.push(-p1);
	while (que.size()>1)
	{
		int x=que.top();que.pop();
		int y=que.top();que.pop();
		ans-=x+y;
		que.push(x+y);
	}
	while (!que.empty()) que.pop();
	return ans;
}

void solve()
{
	for (int i=1,l=1,r=0;i<=m;i++)
	{
		for (;r<q[i].r;r++) updata(r+1,1);
		for (;l>q[i].l;l--) updata(l-1,1);
		for (;r>q[i].r;r--) updata(r,-1);
		for (;l<q[i].l;l++) updata(l,-1);
		ans[q[i].id]=query();
	}
}

int main()
{
	n=read();B=sqrt(n);
	for (int i=1;i<=n;i++) a[i]=read(),bel[i]=(i+B-1)/B,t[a[i]]++;
	for (int i=1;i<=100000;i++)
		if (t[i]>B) vec.push_back(i);
	for (int i=1;i<=n;i++) t[a[i]]--;
	m=read();
	for (int i=1;i<=m;i++) q[i].l=read(),q[i].r=read(),q[i].id=i;
	std::sort(q+1,q+m+1,cmp);
	solve();
	for (int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}