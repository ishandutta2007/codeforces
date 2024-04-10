#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,S=1e5+5,M=5e4;
struct T
{
	struct node{int l,r;pair<int,int> v;}t[S*30];
	int cnt;
	inline void init(){cnt=0;t[0].v.second=-1e9;}
	inline void update(int x)
	{
		t[x].v=max(t[t[x].l].v,t[t[x].r].v);
	}
	void ins(int&x,int l,int r,int p)
	{
		if(!x)x=++cnt,t[x].v.second=-l;
		if(l==r){t[x].v.first++;return;}
		int mid=(l+r)>>1;
		if(p<=mid)ins(t[x].l,l,mid,p);
		else ins(t[x].r,mid+1,r,p);
		update(x);
	}
	int merge(int x,int y,int l,int r)
	{
		if(!x||!y)return x+y;
		int z=++cnt;
		if(l==r){t[z].v.first=t[x].v.first+t[y].v.first;t[z].v.second=-l;return z;}
		int mid=(l+r)>>1;
		t[z].l=merge(t[x].l,t[y].l,l,mid);
		t[z].r=merge(t[x].r,t[y].r,mid+1,r);
		update(z);
		return z;
	}
	pair<int,int> query(int x,int l,int r,int left,int right)
	{
		if(left<=l&&right>=r)return t[x].v;
		int mid=(l+r)>>1;
		if(right<=mid)return query(t[x].l,l,mid,left,right);
		if(left>mid)return query(t[x].r,mid+1,r,left,right);
		return max(query(t[x].l,l,mid,left,right),query(t[x].r,mid+1,r,left,right));
	}
}t;
struct SAM
{
	struct node{int trans[26],fa,len;}s[S];
	int lst,tot,rt[S],sum[S],tmp[S],fa[S][30];
	inline void init(){lst=tot=1;}
	inline void extend(int x,int y)
	{
		int p=lst,q=s[p].trans[x];
		if(q)
		{
			if(s[q].len==s[p].len+1)lst=q;
			else
			{
				int r=++tot;
				s[r].len=s[p].len+1;
				s[r].fa=s[q].fa;
				s[q].fa=r;
				memcpy(s[r].trans,s[q].trans,sizeof(s[q].trans));
				while(p&&s[p].trans[x]==q)s[p].trans[x]=r,p=s[p].fa;
				lst=r;
			}
		}
		else
		{
			int cur=++tot;s[cur].len=s[p].len+1;
			while(p&&!s[p].trans[x])s[p].trans[x]=cur,p=s[p].fa;
			if(!p)s[cur].fa=1;
			else
			{
				int q=s[p].trans[x];
				if(s[q].len==s[p].len+1)s[cur].fa=q;
				else
				{
					int r=++tot;
					s[r].len=s[p].len+1;
					s[r].fa=s[q].fa;
					s[q].fa=s[cur].fa=r;
					memcpy(s[r].trans,s[q].trans,sizeof(s[q].trans));
					while(p&&s[p].trans[x]==q)s[p].trans[x]=r,p=s[p].fa;
				}
			}
			lst=cur;
		}
		if(y)t.ins(rt[lst],1,M,y);
	}
	inline void add(char*t,int id)
	{
		int len=strlen(t);
		lst=1;
		for(int i=0;i<len;i++)extend(t[i]-'a',id);
	}
	inline void work()
	{
		for(int i=1;i<=tot;i++)fa[i][0]=s[i].fa;
		for(int j=1;j<30;j++)
			for(int i=1;i<=tot;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
		for(int i=1;i<=tot;i++)sum[s[i].len]++;
		for(int i=1;i<=tot;i++)sum[i]+=sum[i-1];
		for(int i=1;i<=tot;i++)tmp[sum[s[i].len]--]=i;
		for(int i=tot;i>=1;i--)
		{
			int x=tmp[i];
			if(s[x].fa)rt[s[x].fa]=t.merge(rt[s[x].fa],rt[x],1,M);
		}
	}
	inline int query(int x,int y)
	{
		if(s[x].len<y)return -1;
		for(int i=29;i>=0;i--)if(s[fa[x][i]].len>=y)x=fa[x][i];
		return x;
	}
}sam;
int n,m,pos[N],a[N];
char str[N],s[S];
int main()
{
	t.init();sam.init();
	scanf("%s",str);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",s),sam.add(s,i);
	sam.work();
	int p=1,q=0,len=strlen(str);
	for(int i=0;i<len;i++)
	{
		while(p!=1&&!sam.s[p].trans[str[i]-'a'])p=sam.s[p].fa,q=sam.s[p].len;
		if(sam.s[p].trans[str[i]-'a'])p=sam.s[p].trans[str[i]-'a'],q++;
		pos[i+1]=p;a[i+1]=q;
	}
	scanf("%d",&m);
	while(m--)
	{
		int l,r,L,R;
		scanf("%d%d%d%d",&l,&r,&L,&R);
		if(a[R]<R-L+1){printf("%d %d\n",l,0);continue;}
		int x=sam.query(pos[R],R-L+1);
		pair<int,int> ans=t.query(sam.rt[x],1,M,l,r);
		if(!ans.first)printf("%d %d\n",l,0);
		else printf("%d %d\n",-ans.second,ans.first);
	}
	return 0;
}