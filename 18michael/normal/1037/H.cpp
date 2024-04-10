#include<bits/stdc++.h>
using namespace std;
int q,n,tot=1,las=1,S_t=0;
char ch;
int rt[200002];
char s[100002],s1[200002];
vector<int> vec[200002];
struct aaa
{
	int fa,len;
	int to[26];
}a[200002];
struct SegTree
{
	int lson[20000002],rson[20000002];
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return ;
		int mid=((l+r)>>1);
		if(x<=mid)
		{
			if(!lson[k])lson[k]=(++S_t);
			modify(lson[k],l,mid,x);
		}
		else
		{
			if(!rson[k])rson[k]=(++S_t);
			modify(rson[k],mid+1,r,x);
		}
	}
	inline int merge(int k,int k1,int l,int r)
	{
		if(!k || !k1)return (k|k1);
		if(l==r)return k;
		int mid=((l+r)>>1),k2=(++S_t);
		return lson[k2]=merge(lson[k],lson[k1],l,mid),rson[k2]=merge(rson[k],rson[k1],mid+1,r),k2;
	}
	inline bool query(int k,int l,int r,int l1,int r1)
	{
		if(!k)return 0;
		if(l>=l1 && r<=r1)return 1;
		int mid=((l+r)>>1);
		if(r1<=mid)return query(lson[k],l,mid,l1,r1);
		if(l1>mid)return query(rson[k],mid+1,r,l1,r1);
		return (query(lson[k],l,mid,l1,mid)|query(rson[k],mid+1,r,mid+1,r1));
	}
}S;
inline void add(int c,int x)
{
	int p=las,np=(++tot),q,nq;
	a[las=np].len=a[p].len+1,S.modify(rt[np]=(++S_t),1,n,x);
	while(p && !a[p].to[c])a[p].to[c]=np,p=a[p].fa;
	if(!p)a[np].fa=1;
	else
	{
		q=a[p].to[c];
		if(a[q].len==a[p].len+1)a[np].fa=q;
		else
		{
			a[nq=(++tot)]=a[q],a[nq].len=a[p].len+1,a[np].fa=a[q].fa=nq;
			while(p && a[p].to[c]==q)a[p].to[c]=nq,p=a[p].fa;
		}
	}
}
inline void dfs(int x)
{
	for(int i=0;i<vec[x].size();++i)dfs(vec[x][i]),rt[x]=S.merge(rt[x],rt[vec[x][i]],1,n);
}
int main()
{
	scanf("%s%d",s+1,&q),n=strlen(s+1);
	for(int i=1;i<=n;++i)add(s[i]-'a',i);
	for(int i=2;i<=tot;++i)vec[a[i].fa].push_back(i);
	dfs(1);
	for(int x,y,l,t,now,pos;q--;)
	{
		for(scanf("%d%d%s",&x,&y,s1+1),l=strlen(s1+1),pos=0,t=now=1;;++t)
		{
			for(int i=max(s1[t]-'a'+1,0);i<26;++i)
				if(a[now].to[i] && S.query(rt[a[now].to[i]],1,n,x+t-1,y))
				{
					pos=t,ch='a'+i;
					break;
				}
			if(s1[t] && a[now].to[s1[t]-'a'] && S.query(rt[a[now].to[s1[t]-'a']],1,n,x+t-1,y))
			{
				now=a[now].to[s1[t]-'a'];
				continue;
			}
			break;
		}
		if(!pos)puts("-1");
		else
		{
			for(int i=1;i<pos;++i)putchar(s1[i]);
			putchar(ch),puts("");
		}
	}
	return 0;
}