#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define N 400050
priority_queue<pair<long long,int> > st1,st2;
priority_queue<int> v1,v2;
int fa[N],ch[N][2],mx[N],fr[N],n,m,s[N][3],vl[N],lz[N],sz[N],ls[N],st[N],ras,nw;
int Max(int x,int y){return x>y?x:y;}
bool nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
void pushup(int x){mx[x]=Max(Max(mx[ch[x][0]],mx[ch[x][1]]),vl[x]);if(mx[x]==vl[x])fr[x]=x;else if(mx[x]==mx[ch[x][0]])fr[x]=fr[ch[x][0]];else fr[x]=fr[ch[x][1]];sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+(x<=n)+ls[x];}
void pushdown(int x){if(lz[x])lz[ch[x][0]]^=1,lz[ch[x][1]]^=1,lz[x]=0,swap(ch[ch[x][0]][0],ch[ch[x][0]][1]),swap(ch[ch[x][1]][0],ch[ch[x][1]][1]);}
void rotate(int x){int f=fa[x],g=fa[f],tp=ch[f][1]==x;if(nroot(f))ch[g][ch[g][1]==f]=x;fa[x]=g;ch[f][tp]=ch[x][!tp];fa[ch[x][!tp]]=f;ch[x][!tp]=f;fa[f]=x;pushup(f);pushup(x);}
void splay(int x)
{
	int ct=1,st1=x;st[1]=x;
	while(nroot(st1)&&st1)st1=fa[st1],st[++ct]=st1;
	for(int i=ct;i>=1;i--)pushdown(st[i]);
	while(nroot(x)){int f=fa[x],g=fa[f];if(nroot(f))rotate((ch[f][1]==x)^(ch[g][1]==f)?x:f);rotate(x);}
}
void access(int x){int tp=0;while(x)splay(x),ls[x]=ls[x]+sz[ch[x][1]]-sz[tp],ch[x][1]=tp,pushup(x),tp=x,x=fa[x];}
int findroot(int x){access(x);splay(x);while(ch[x][0])x=ch[x][0];return x;}
void makeroot(int x){access(x);splay(x);lz[x]^=1;swap(ch[x][0],ch[x][1]);}
void split(int x,int y){makeroot(x);access(y);splay(y);}
void link(int x,int y){makeroot(x);makeroot(y);fa[x]=y;ls[y]+=sz[x];pushup(y);}
void cut(int x,int y){split(x,y);fa[x]=ch[y][0]=0;pushup(y);}
int main()
{
	scanf("%d%d",&n,&m);
	if(n&1){for(int i=1;i<=m;i++)printf("-1\n");return 0;}
	for(int i=1;i<=n;i++)sz[i]=1;
	nw=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&s[i][0],&s[i][1],&s[i][2]);
		vl[i+n]=s[i][2];
		if(findroot(s[i][0])!=findroot(s[i][1])){
		makeroot(s[i][0]);
		makeroot(s[i][1]);if((sz[s[i][0]]&1)&&(sz[s[i][1]]&1))nw-=2;v1.push(s[i][2]);st1.push(make_pair(s[i][2],i));
		link(s[i][0],i+n);link(s[i][1],i+n);}
		else
		{
			split(s[i][0],s[i][1]);
			int tp=fr[s[i][1]]-n;
			if(s[tp][2]>s[i][2])
			{
				st2.push(make_pair(s[tp][2],tp));
				v2.push(s[tp][2]);
				st1.push(make_pair(s[i][2],i));
				v1.push(s[i][2]);
				cut(s[tp][0],tp+n);cut(s[tp][1],tp+n);
				link(s[i][0],i+n);link(s[i][1],i+n);
			}
		}
		if(nw)printf("-1\n");
		else
		{
			while(!st1.empty())
			{
				while(st2.size()&&st1.top()==st2.top())st1.pop(),st2.pop();
				int r=st1.top().second;
				split(s[r][0],s[r][1]);
				splay(s[r][0]);
				if(sz[s[r][1]]&1)break;
				cut(s[r][0],r+n);cut(s[r][1],r+n);
				st2.push(make_pair(s[r][2],r));
				v2.push(s[r][2]);
			}
			while(v2.size()&&v1.top()==v2.top())v1.pop(),v2.pop();
			printf("%d\n",v1.top());
		}
	}
}//