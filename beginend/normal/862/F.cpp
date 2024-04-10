#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb(x) push_back(x)
using namespace std;

const int N=100005;
const int K=70;

int n,q,a[N],tmp[N],len[N],sz,stack[N],lcp[N],root[K+5],nx[N];
char str[N];
struct tree{int l,r,lef,rig,mx;}t[N*K*3];
vector<int> vec[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct Segment_Tree
{
	struct tree{int mx;}t[N*4];
	
	void modify(int d,int l,int r,int x)
	{
		if (l==r) {t[d].mx=len[x];return;}
		int mid=(l+r)/2;
		if (x<=mid) modify(d*2,l,mid,x);
		else modify(d*2+1,mid+1,r,x);
		t[d].mx=max(t[d*2].mx,t[d*2+1].mx);
	}
	
	int query(int d,int l,int r,int x,int y)
	{
		if (l==x&&r==y) return t[d].mx;
		int mid=(l+r)/2;
		if (y<=mid) return query(d*2,l,mid,x,y);
		else if (x>mid) return query(d*2+1,mid+1,r,x,y);
		else return max(query(d*2,l,mid,x,mid),query(d*2+1,mid+1,r,mid+1,y));
	}
}t1;

int get_lcp(int x,int y)
{
	for (int i=0;i<min(len[x],len[y]);i++)
		if (vec[x][i]!=vec[y][i]) return i;
	return min(len[x],len[y]);
}

void updata(int d,int l,int r)
{
	int mid=(l+r)/2;
	t[d].mx=max(max(t[t[d].l].mx,t[t[d].r].mx),t[t[d].l].rig+t[t[d].r].lef);
	t[d].lef=t[t[d].l].lef;t[d].rig=t[t[d].r].rig;
	if (t[d].lef==mid-l+1) t[d].lef+=t[t[d].r].lef;
	if (t[d].rig==r-mid) t[d].rig+=t[t[d].l].rig;
}

void modify(int &d,int l,int r,int x,int y)
{
	if (!d) d=++sz;
	if (l==r) {t[d].lef=t[d].rig=t[d].mx=y;return;}
	int mid=(l+r)/2;
	if (x<=mid) modify(t[d].l,l,mid,x,y);
	else modify(t[d].r,mid+1,r,x,y);
	updata(d,l,r);
}

int query(int d,int l,int r,int x,int y)
{
	if (l==x&&r==y) return t[d].mx;
	int mid=(l+r)/2;
	if (y<=mid) return query(t[d].l,l,mid,x,y);
	else if (x>mid) return query(t[d].r,mid+1,r,x,y);
	else return max(max(query(t[d].l,l,mid,x,mid),query(t[d].r,mid+1,r,mid+1,y)),min(t[t[d].l].rig,mid-x+1)+min(t[t[d].r].lef,y-mid));
}

void change(int x,int ty)
{
	if (lcp[x]<=K)
	{
		for (int i=1;i<=lcp[x];i++) modify(root[i],1,n,x,ty);
	}
	else if (!ty)
	{
		for (int i=1;i<=K;i++) modify(root[i],1,n,x,0);
		int p=0;
		while (nx[p]!=x) p=nx[p];
		nx[p]=nx[x];nx[x]=0;
	}
	else
	{
		for (int i=1;i<=K;i++) modify(root[i],1,n,x,1);
		int p=0;
		while (nx[p]&&nx[p]<x) p=nx[p];
		nx[x]=nx[p];nx[p]=x;
	}
}

int solve(int l,int r)
{
	int p=0,tot=0,top=0,ans=0;;
	while (nx[p]) p=nx[p],a[++tot]=p,tot-=(p<l||p>r)?1:0;
	stack[0]=a[1]-1;
	for (int i=1;i<=tot;i++)
	{
		if (top&&stack[top]!=a[i]-1) top=0,stack[0]=a[i]-1;
		while (top&&lcp[stack[top]]>=lcp[a[i]]) top--;
		tmp[i]=stack[top];stack[++top]=a[i];
	}
	top=0;stack[0]=a[tot]+1;
	for (int i=tot;i>=1;i--)
	{
		if (top&&stack[top]!=a[i]+1) top=0,stack[0]=a[i]+1;
		while (top&&lcp[stack[top]]>=lcp[a[i]]) top--;
		ans=max(ans,lcp[a[i]]*(stack[top]-tmp[i]));stack[++top]=a[i];
	}
	return ans;
}

int main()
{
	n=read();q=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str);len[i]=strlen(str);
		for (int j=0;j<len[i];j++) vec[i].pb(str[j]-'a');
		t1.modify(1,1,n,i);lcp[i]=get_lcp(i,i-1);change(i,1);
	}
	while (q--)
	{
		int op=read();
		if (op==1)
		{
			int l=read(),r=read(),ans=t1.query(1,1,n,l,r);
			if (l==r) {printf("%d\n",ans);continue;}
			for (int i=1,w;i<=K;i++) w=query(root[i],1,n,l+1,r),ans=max(ans,i*((w>0?w:-1)+1));
			ans=max(ans,solve(l+1,r));
			printf("%d\n",ans);
		}
		else
		{
			int x=read();scanf("%s",str);
			len[x]=strlen(str);vec[x].clear();
			for (int i=0;i<len[x];i++) vec[x].pb(str[i]-'a');
			t1.modify(1,1,n,x);
			change(x,0);lcp[x]=get_lcp(x,x-1);change(x,1);
			if (x==n) continue;
			change(x+1,0);lcp[x+1]=get_lcp(x,x+1);change(x+1,1);
		}
	}
	return 0;
}