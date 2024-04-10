#include<bits/stdc++.h>
namespace Solution
{
	int n,q,m;
	int max(int x,int y){return x<y?y:x;}
	struct segt
	{
		int f[1111111];
		void ins(int x,int d,int p=1,int pl=1,int pr=n)
		{
			//if(p==1)printf("ins %d\n",x);
			if(f[p]<d)f[p]=d;
			if(pl==pr)return;
			int pm=(pl+pr)>>1,dr=x>pm;
			dr?pl=pm+1:pr=pm,ins(x,d,p<<1|dr,pl,pr);
		}
		void clear(int p=1)
		{
			//if(p==1)puts("clear");
			if(f[p<<1])clear(p<<1);
			if(f[p<<1|1])clear(p<<1|1);
			f[p]=0;
		}
		int check(int l,int r,int p=1,int pl=1,int pr=n)
		{
			if(l>pr||pl>r)return 0;
			if(l<=pl&&pr<=r)return f[p];
			int pm=(pl+pr)>>1;
			return max(check(l,r,p<<1,pl,pm),check(l,r,p<<1|1,pm+1,pr));
		}
	}T;
	std::vector<int>w[1111111],e[1111111];
	int l[1111111],r[1111111],ans[1111111],fa[1111111];
	int qq[1111111];
	int vis[1111111];
	void bfs(int L,int R,int s)
	{
		register int ql=1,qr=1;qq[1]=s,vis[s]=s;
		for(;ql<=qr;ql++)
		{
			int p=qq[ql];
			//printf("? %d\n",p);
			T.ins(p,vis[p]);
			if(fa[p])T.ins(fa[p],vis[p]);
			int d=p<vis[p]?p:vis[p];
			if(p+1<=R)if(vis[p+1]<d)vis[p+1]=d,qq[++qr]=p+1;
			if(fa[p]>=L)if(vis[fa[p]]<d)vis[fa[p]]=d,qq[++qr]=fa[p];
		}
	}
	void solve(int L=1,int R=n,int p=1)
	{
		//printf("[%d %d]\n",L,R);
		if(L>R)return;
		int M=(L+R)>>1;
		for(int qid:w[p])
		{
			if(l[qid]>M)w[p<<1|1].push_back(qid);
			else if(r[qid]<M)w[p<<1].push_back(qid);
			else e[r[qid]].push_back(qid);
		}
		T.clear();
		for(register int i=L;i<=R;i++)vis[i]=0;
		for(register int i=M;i<=R;i++)
		{
			bfs(L,i,i);
			for(int qid:e[i])
			{
				//printf("check [%d,%d]?\n",l[qid],ans[qid]);
				if(T.check(l[qid],ans[qid])>=l[qid])
					ans[qid]=M,w[p<<1|1].push_back(qid);
				else r[qid]=M-1,w[p<<1].push_back(qid);
			}
			e[i].clear();
		}
		solve(L,M-1,p<<1),solve(M+1,R,p<<1|1);
	}
	void execute()
	{
		scanf("%d%d",&n,&m);
		register int i;
		for(i=1;i<=m;i++){int x,y;scanf("%d%d",&x,&y),fa[y]=x;}
		scanf("%d",&q);
		for(i=1;i<=q;i++)scanf("%d%d",l+i,r+i),ans[i]=l[i],w[1].push_back(i);
		solve();
		for(i=1;i<=q;i++)printf("%d\n",ans[i]);
	}
}
int main()
{
	Solution::execute();
}