#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int N=400005;
struct node
{
	int x,l,r;
	bool t,ok;
}a[N],b[N];
struct mode
{
	int x,y,f;
}g[N];
bool operator <(node a,node b)
{
	if(a.l!=b.l)
		return a.l<b.l;
	if(a.r!=b.r)
		return a.r<b.r;
	return a.x<b.x;
}
vector<int> vct1[100005],vct2[100005];
multiset<int> st;
multiset<node> st1[100005],st2[100005];
map<int,int> mp[N][4];
int n,m,i,j,k,x,y,z,f,q,l1,l2,cnt,nxt[N],len[N],p[N][56],pt[N];
char s[10];
long long T[N],dis[N][56],cirno=10000000000000000ll;
bool cmp(node a,node b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.l<b.l;
}
long long Abs(long long a)
{
	return a>0?a:-a;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d%d",&j,&k,&x,&y);
		if(j==x)
		{
			if(k<y)
				f=0;
			else
				f=1;
		}
		else
		{
			if(j>x)
				f=2;
			else
				f=3;
		}
		if(!mp[x][f].count(y))
		{
			g[++cnt]=(mode){x,y,f};
			mp[x][f][y]=cnt;
		}
		if(j==x)
		{
			if(k<y)
				a[++l1]=(node){j,k,y,true,true};
			else
				a[++l1]=(node){j,y,k,false,true};
		}
		else
		{
			if(j<x)
				b[++l2]=(node){k,j,x,true,true};
			else
				b[++l2]=(node){k,x,j,false,true};
		}
	}
	for(i=1;i<=l1;++i)
		st1[a[i].x].insert(a[i]);
	for(i=1;i<=l2;++i)
		st2[b[i].x].insert(b[i]);
	scanf("%d",&q);
	for(i=1;i<=q;++i)
	{
		scanf("%d%d%s%lld",&j,&k,s,T+i);
		multiset<node>::iterator ddq=st1[j].upper_bound((node){j,k,1<<30,0,0});
		if(s[0]=='U')
			f=0;
		else if(s[0]=='D')
			f=1;
		else if(s[0]=='L')
			f=2;
		else
			f=3;
		if(ddq!=st1[j].begin())
		{
			ddq--;
			if((ddq->r)>=k)
			{
				if(ddq->t)
					f=0,s[0]='U';
				else
					f=1,s[0]='D';
			}
		}
		ddq=st2[k].upper_bound((node){k,j,1<<30,0,0});
		if(ddq!=st2[k].begin())
		{
			ddq--;
			if((ddq->r)>=j)
			{
				if(ddq->t)
					f=3,s[0]='R';
				else
					f=2,s[0]='L';
			}
		}
		if(s[0]=='U'||s[0]=='D')
			a[++l1]=(node){j,k,k,s[0]=='U',false};
		else
			b[++l2]=(node){k,j,j,s[0]=='R',false};
		if(!mp[j][f].count(k))
		{
			g[++cnt]=(mode){j,k,f};
			mp[j][f][k]=cnt;
		}
		pt[i]=mp[j][f][k];
	}
	sort(a+1,a+1+l1,cmp);
	for(i=0;i<=m+1;++i)
		vct1[i].clear(),vct2[i].clear();
	for(i=1;i<=l2;++i)
		if(b[i].ok)
			vct1[b[i].l].push_back(b[i].x),vct2[b[i].r+1].push_back(b[i].x);
	st.clear();
	for(i=1,j=0;i<=l1;++i)
	{
		while(j<=a[i].x)
		{
			for(k=vct1[j].size()-1;k>=0;--k)
				st.insert(vct1[j][k]);
			for(k=vct2[j].size()-1;k>=0;--k)
				st.erase(st.find(vct2[j][k]));
			++j;
		}
		multiset<int>::iterator ddq;
		if(a[i].t)
		{
			k=m;
			ddq=st.lower_bound(a[i].r);
			if(ddq!=st.end())
				k=min(k,*ddq);
			multiset<node>::iterator dzx=st1[a[i].x].lower_bound((node){a[i].x,a[i].r,-(1<<30),0,0});
			if(dzx!=st1[a[i].x].end())
				k=min(k,dzx->t?dzx->r:dzx->l);
		}
		else
		{
			k=0;
			ddq=st.upper_bound(a[i].l);
			if(ddq!=st.begin())
			{
				ddq--;
				k=max(k,*ddq);
			}
			multiset<node>::iterator dzx=st1[a[i].x].lower_bound((node){a[i].x,a[i].l,-(1<<30),0,0});
			if(dzx!=st1[a[i].x].begin())
			{
				dzx--;
				if((dzx->r)<=a[i].l)
					k=max(k,dzx->t?dzx->r:dzx->l);
			}
		}
		f=(a[i].t?0:1);
		if(!mp[a[i].x][f].count(k))
		{
			g[++cnt]=(mode){a[i].x,k,f};
			mp[a[i].x][f][k]=cnt;
		}
		nxt[mp[a[i].x][f][a[i].t?a[i].r:a[i].l]]=mp[a[i].x][f][k];
	}
	sort(b+1,b+1+l2,cmp);
	for(i=0;i<=m+1;++i)
		vct1[i].clear(),vct2[i].clear();
	for(i=1;i<=l1;++i)
		if(a[i].ok)
			vct1[a[i].l].push_back(a[i].x),vct2[a[i].r+1].push_back(a[i].x);
	st.clear();
	for(i=1,j=0;i<=l2;++i)
	{
		while(j<=b[i].x)
		{
			for(k=vct1[j].size()-1;k>=0;--k)
				st.insert(vct1[j][k]);
			for(k=vct2[j].size()-1;k>=0;--k)
				st.erase(st.find(vct2[j][k]));
			++j;
		}
		multiset<int>::iterator ddq;
		if(b[i].t)
		{
			k=m;
			ddq=st.lower_bound(b[i].r);
			if(ddq!=st.end())
				k=min(k,*ddq);
			multiset<node>::iterator dzx=st2[b[i].x].lower_bound((node){b[i].x,b[i].r,-(1<<30),0,0});
			if(dzx!=st2[b[i].x].end())
				k=min(k,dzx->t?dzx->r:dzx->l);
		}
		else
		{
			k=0;
			ddq=st.upper_bound(b[i].l);
			if(ddq!=st.begin())
			{
				ddq--;
				k=max(k,*ddq);
			}
			multiset<node>::iterator dzx=st2[b[i].x].lower_bound((node){b[i].x,b[i].l,-(1<<30),0,0});
			if(dzx!=st2[b[i].x].begin())
			{
				dzx--;
				if((dzx->r)<=b[i].l)
					k=max(k,dzx->t?dzx->r:dzx->l);
			}
		}
		f=(b[i].t?3:2);
		if(!mp[k][f].count(b[i].x))
		{
			g[++cnt]=(mode){k,b[i].x,f};
			mp[k][f][b[i].x]=cnt;
		}
		nxt[mp[b[i].t?b[i].r:b[i].l][f][b[i].x]]=mp[k][f][b[i].x];
	}
	for(i=1;i<=cnt;++i)
	{
		multiset<node>::iterator dzx=st1[g[i].x].upper_bound((node){g[i].x,g[i].y,1<<30,0,0});
		if(dzx!=st1[g[i].x].begin())
		{
			dzx--;
			if((dzx->r)>=g[i].y)
			{
				f=(dzx->t?0:1);
				if(mp[g[i].x][f][dzx->t?dzx->r:dzx->l]!=mp[g[i].x][g[i].f][g[i].y])
					nxt[mp[g[i].x][g[i].f][g[i].y]]=mp[g[i].x][f][dzx->t?dzx->r:dzx->l];
			}
		}
		dzx=st2[g[i].y].upper_bound((node){g[i].y,g[i].x,1<<30,0,0});
		if(dzx!=st2[g[i].y].begin())
		{
			dzx--;
			if((dzx->r)>=g[i].x)
			{
				f=(dzx->t?3:2);
				if(mp[dzx->t?dzx->r:dzx->l][f][g[i].y]!=mp[g[i].x][g[i].f][g[i].y])
					nxt[mp[g[i].x][g[i].f][g[i].y]]=mp[dzx->t?dzx->r:dzx->l][f][g[i].y];
			}
		}
	}
	for(i=1;i<=cnt;++i)
		if(nxt[i])
		{
			p[i][0]=nxt[i];
			dis[i][0]=(g[i].x==g[nxt[i]].x?Abs(g[i].y-g[nxt[i]].y):Abs(g[i].x-g[nxt[i]].x));
		}
	for(i=1;i<=55;++i)
		for(j=1;j<=cnt;++j)
			if(p[j][i-1])
			{
				p[j][i]=p[p[j][i-1]][i-1];
				if(dis[j][i-1]>=cirno||dis[p[j][i-1]][i-1]>=cirno)
					dis[j][i]=cirno;
				else
					dis[j][i]=dis[j][i-1]+dis[p[j][i-1]][i-1];
			}
	for(i=1;i<=q;++i)
	{
		for(j=55,k=pt[i];j>=0;--j)
			if(p[k][j]&&dis[k][j]<=T[i])
			{
				T[i]-=dis[k][j];
				k=p[k][j];
			}
		if(!nxt[k]||nxt[k]==k)
			printf("%d %d\n",g[k].x,g[k].y);
		else
		{
			if(g[k].x==g[nxt[k]].x)
				printf("%d %lld\n",g[k].x,g[k].y+T[i]*(g[nxt[k]].y>g[k].y?1:-1));
			else
				printf("%lld %d\n",g[k].x+T[i]*(g[nxt[k]].x>g[k].x?1:-1),g[k].y);
		}
	}
	return 0;
}