#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=100005;

int n,w1[N*2],w2[N*2],tot;
bool vis[N];
struct data{int x,op,id;}p[N*2];
struct pts{int x1,y1,x2,y2;}a[N];
struct Queue
{
	std::priority_queue<int> a,b;
	
	void work() {while (!b.empty()&&a.top()==b.top()) a.pop(),b.pop();}
	int top() {work();return a.top();}
	bool empty() {work();return a.empty();}
	void push(int x) {a.push(x);}
	void erase(int x) {b.push(x);}
};
struct tree{int mx,mn;Queue col;}t[N*8];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool cmp(data a,data b)
{
	return a.x>b.x||a.x==b.x&&a.op<b.op;
}

void updata(int d,int l,int r)
{
	if (l!=r)
	{
		t[d].mn=std::min(t[d*2].mn,t[d*2+1].mn);
		t[d].mx=std::max(t[d*2].mx,t[d*2+1].mx);
	}
	else t[d].mn=t[d].mx=0;
	if (!t[d].col.empty())
	{
		int x=t[d].col.top();
		if (vis[x]) t[d].mn=std::max(t[d].mn,x);
		else t[d].mx=std::max(t[d].mx,x);
		if (t[d].mn>t[d].mx) t[d].mx=0;
	}
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x<=l&&r<=y)
	{
		if (z>0) t[d].col.push(z);
		else if (z<0) t[d].col.erase(-z);
		updata(d,l,r);
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) ins(d*2,l,mid,x,y,z);
	if (y>mid) ins(d*2+1,mid+1,r,x,y,z);
	updata(d,l,r);
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i].x1=read();a[i].y1=read();a[i].x2=read();a[i].y2=read();
		w1[i*2-1]=a[i].x1;w1[i*2]=a[i].x2;w2[i*2-1]=a[i].y1;w2[i*2]=a[i].y2;
	}
	std::sort(w1+1,w1+n*2+1);
	std::sort(w2+1,w2+n*2+1);
	for (int i=1;i<=n;i++)
	{
		a[i].x1=std::lower_bound(w1+1,w1+n*2+1,a[i].x1)-w1;
		a[i].x2=std::lower_bound(w1+1,w1+n*2+1,a[i].x2)-w1;
		a[i].y1=std::lower_bound(w2+1,w2+n*2+1,a[i].y1)-w2;
		a[i].y2=std::lower_bound(w2+1,w2+n*2+1,a[i].y2)-w2-1;
		p[++tot].x=a[i].x2;p[tot].op=0;p[tot].id=i;
		p[++tot].x=a[i].x1;p[tot].op=1;p[tot].id=i;
	}
	std::sort(p+1,p+tot+1,cmp);
	int l=1,ans=0;
	while (l<=tot)
	{
		int r=l;
		while (r<tot&&p[r+1].x==p[l].x) r++;
		while (l<=r)
		{
			if (!p[l].op) ins(1,1,n*2,a[p[l].id].y1,a[p[l].id].y2,p[l].id);
			else ins(1,1,n*2,a[p[l].id].y1,a[p[l].id].y2,-p[l].id);
			l++;
		}
		while (t[1].mx)
		{
			ans++;int x=t[1].mx;vis[x]=1;
			ins(1,1,n*2,a[x].y1,a[x].y2,0);
		}
	}
	printf("%d",ans+1);
	return 0;
}