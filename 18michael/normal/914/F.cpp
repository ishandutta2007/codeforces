#include<bits/stdc++.h>
#define B 316
#define bs 233
#define LL long long
using namespace std;
int q,l,l1,ans,las;
LL tmp;
int bl[100002];
LL Hs[100002],Hs1[322],pw[100002];
char s[100002],s1[100002];
vector<int> vec[642];
struct SAM
{
	int tot;
	int len[642],fa[642],tim[642];
	int to[642][26];
	inline void ins(int c)
	{
		int p=las,np=(++tot),q,nq;
		len[np]=len[p]+1,tim[las=np]=1;
		while(p && !to[p][c])to[p][c]=np,p=fa[p];
		if(!p)fa[np]=1;
		else
		{
			q=to[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else
			{
				fa[nq=(++tot)]=fa[q];
				for(int i=0;i<26;++i)to[nq][i]=to[q][i];
				len[nq]=len[p]+1,fa[np]=fa[q]=nq;
				while(p && to[p][c]==q)to[p][c]=nq,p=fa[p];
			}
		}
	}
	inline void dfs(int x)
	{
		for(int i=0;i<vec[x].size();++i)dfs(vec[x][i]),tim[x]+=tim[vec[x][i]];
	}
	inline void build(int l,int r)
	{
		las=tot=1,memset(len,0,sizeof(len)),memset(fa,0,sizeof(fa)),memset(tim,0,sizeof(tim)),memset(to,0,sizeof(to));
		for(int i=l;i<=r;++i)ins(s[i]-'a');
		for(int i=1;i<=tot;++i)vec[i].clear();
		for(int i=tot;i>1;--i)vec[fa[i]].push_back(i);
		dfs(1);
	}
	inline int query()
	{
		int now=1;
		for(int i=1;i<=l1;++i)if(!(now=to[now][s1[i]-'a']))return 0;
		return tim[now];
	}
}a[322];
inline LL calc(int x)
{
	return Hs1[(x-1)/B]*pw[x-(x-1)/B*B]+Hs[x];
}
inline LL getHs(int x,int y)
{
	return calc(y)-calc(x-1)*pw[y-x+1];
}
inline void solve(int x,int y,int z)
{
	for(int i=x;i<=y && i+l1-1<=z;++i)ans+=(getHs(i,i+l1-1)==tmp);
}
int main()
{
	scanf("%s%d",s+1,&q),l=strlen(s+1),pw[0]=1;
	for(int i=1;i<=l;++i)Hs[i]=((i-1)%B? Hs[i-1]:0)*bs+s[i],Hs1[(i-1)/B+1]=Hs1[(i-1)/B+1]*bs+s[i],pw[i]=pw[i-1]*bs;
	for(int i=1;i<=(l-1)/B+1;++i)a[i].build((i-1)*B+1,min(i*B,l)),Hs1[i]+=Hs1[i-1]*pw[B];
	for(int o,x,y,st,ed;q--;)
	{
		scanf("%d%d",&o,&x);
		if(o==1)
		{
			do s[x]=getchar();while(s[x]<'a' || s[x]>'z');
			for(int i=(l-1)/B+1;i>1;--i)Hs1[i]-=Hs1[i-1]*pw[B];
			Hs1[(x-1)/B+1]=0,a[(x-1)/B+1].build(st=((x-1)/B)*B+1,ed=min(((x-1)/B+1)*B,l));
			for(int i=st;i<=ed;++i)Hs[i]=((i-1)%B? Hs[i-1]:0)*bs+s[i],Hs1[(i-1)/B+1]=Hs1[(i-1)/B+1]*bs+s[i];
			for(int i=2;i<=(l-1)/B+1;++i)Hs1[i]+=Hs1[i-1]*pw[B];
		}
		else
		{
			scanf("%d%s",&y,s1+1),l1=strlen(s1+1),tmp=ans=0;
			for(int i=1;i<=l1;++i)tmp=tmp*bs+s1[i];
			if(l1>B || (x-1)/B==(y-1)/B)solve(x,y,y);
			else
			{
				solve(x,((x-1)/B+1)*B,y),solve(((y-1)/B)*B+1,y,y);
				for(int i=(x-1)/B+2;i<=(y-1)/B;++i)ans+=a[i].query(),solve(i*B-l1+2,i*B,y);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}