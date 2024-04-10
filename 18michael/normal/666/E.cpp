#include<bits/stdc++.h>
#define Mx 19
using namespace std;
int l,m,tot=1,S_t=0,p,Q;
int rt[1000002],len[1000002],pos[500002],mxl[500002];
char s[500002],s1[50002];
int to[1000002][26],fa[1000002][22];
queue<int> q;
vector<int> vec[1000002];
struct aaa
{
	int mx,num;
}tmp;
inline aaa Merge(aaa a,aaa b)
{
	return (a.mx>b.mx || (a.mx==b.mx && a.num<b.num))? a:b;
}
struct SegTree
{
	aaa a[30000002];
	int lson[30000002],rson[30000002];
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return (void)(a[k]=(aaa){a[k].mx+1,l});
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
		a[k]=Merge(a[lson[k]],a[rson[k]]);
	}
	inline int merge(int k,int k1,int l,int r)
	{
		if(!k || !k1)return (k|k1);
		int k2=(++S_t),mid=((l+r)>>1);
		if(l==r)return a[k2]=(aaa){a[k].mx+a[k1].mx,l},k2;
		lson[k2]=merge(lson[k],lson[k1],l,mid),rson[k2]=merge(rson[k],rson[k1],mid+1,r),a[k2]=Merge(a[lson[k2]],a[rson[k2]]);
		return k2;
	}
	inline aaa query(int k,int l,int r,int l1,int r1)
	{
		if(!k)return (aaa){0,0};
		if(l>=l1 && r<=r1)return a[k];
		int mid=((l+r)>>1);
		if(r1<=mid)return query(lson[k],l,mid,l1,r1);
		if(l1>mid)return query(rson[k],mid+1,r,l1,r1);
		return Merge(query(lson[k],l,mid,l1,mid),query(rson[k],mid+1,r,mid+1,r1));
	}
}S;
inline void ins(int p,int c)
{
	int np=to[p][c],q,nq;
	len[np]=len[p]+1,p=fa[p][0];
	while(p && !to[p][c])to[p][c]=np,p=fa[p][0];
	if(!p)fa[np][0]=1;
	else
	{
		q=to[p][c];
		if(len[q]==len[p]+1)fa[np][0]=q;
		else
		{
			fa[nq=(++tot)][0]=fa[q][0];
			for(int i=0;i<26;++i)to[nq][i]=(len[to[q][i]]? to[q][i]:0);
			len[nq]=len[p]+1,fa[np][0]=fa[q][0]=nq;
			while(p && to[p][c]==q)to[p][c]=nq,p=fa[p][0];
		}
	}
}
inline void dfs(int x)
{
	for(int i=0;i<vec[x].size();++i)dfs(vec[x][i]),rt[x]=S.merge(rt[x],rt[vec[x][i]],1,m);
}
int main()
{
	scanf("%s%d",s+1,&m),l=strlen(s+1),q.push(pos[0]=1);
	for(int i=1,l1,now;i<=m;++i)
	{
		scanf("%s",s1+1),l1=strlen(s1+1),now=1;
		for(int j=1;j<=l1;++j)
		{
			if(!to[now][s1[j]-'a'])rt[to[now][s1[j]-'a']=(++tot)]=(++S_t);
			S.modify(rt[now=to[now][s1[j]-'a']],1,m,i);
		}
	}
	while(!q.empty())
	{
		p=q.front(),q.pop();
		for(int i=0;i<26;++i)if(to[p][i])ins(p,i),q.push(to[p][i]);
	}
	for(int i=2;i<=tot;++i)vec[fa[i][0]].push_back(i);
	dfs(1);
	for(int i=1;i<=Mx;++i)for(int j=1;j<=tot;++j)fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<=l;++i)
	{
		for(pos[i]=pos[i-1],mxl[i]=mxl[i-1];pos[i] && !to[pos[i]][s[i]-'a'];mxl[i]=len[pos[i]=fa[pos[i]][0]]);
		pos[i]=(pos[i]? ++mxl[i],to[pos[i]][s[i]-'a']:1);
	}
	scanf("%d",&Q);
	for(int x,y,z,w;Q--;)
	{
		scanf("%d%d%d%d",&x,&y,&z,&w),p=pos[w];
		if(mxl[w]<w-z+1)
		{
			printf("%d %d\n",x,0);
			continue;
		}
		for(int i=Mx;~i;--i)if(len[fa[p][i]]>=w-z+1)p=fa[p][i];
		tmp=S.query(rt[p],1,m,x,y),printf("%d %d\n",tmp.num? tmp.num:x,tmp.mx);
	}
	return 0;
}