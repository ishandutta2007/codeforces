#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define M ((ll)1000*1000+100)
struct Node
{
	ll nex[26],pre,par;
	char ch;
	Node(){for(int i=0;i<26;i++)nex[i]=0;}
};

ll n,q,cnt_node=1,strt[M],fnsh[M],_cnt=1,num[N],fen[M];
bool mark[N];
char exx[M];
string s[N],str;
Node a[M];
vector <ll> e[M];

void build()
{
	for(int i=0;i<n;i++)
	{
		ll now=0;
		for(int j=0;j<s[i].size();j++)
		{
			if(!a[now].nex[s[i][j]-'a'])a[cnt_node].par=now,a[cnt_node].ch=s[i][j],a[now].nex[s[i][j]-'a']=cnt_node,cnt_node++;
			now=a[now].nex[s[i][j]-'a'];
		}
		num[i]=now;
	}
	queue <ll> q;
	for(int i=0;i<26;i++)
		if(a[0].nex[i])
			q.push(a[0].nex[i]);
	while(q.size())
	{
		ll x=q.front();q.pop();
		if(a[x].par!=0)a[x].pre=a[a[a[x].par].pre].nex[a[x].ch-'a'];
		e[a[x].pre].push_back(x);
		for(int i=0;i<26;i++)
		{
			if(!a[x].nex[i])
				a[x].nex[i]=a[a[x].pre].nex[i];
			else
				q.push(a[x].nex[i]);
		}
	}
}

void dfs(ll x)
{
	strt[x]=_cnt++;
	for(auto u:e[x])
		dfs(u);
	fnsh[x]=_cnt;
}

ll query(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}
void update2(ll x,ll val){for(;x<M;x+=x&-x)fen[x]+=val;}
void update(ll l,ll r,ll val){update2(l,val);update2(r,-val);}

long long calc()
{
	long long ans=0;
	ll now=0;
	for(int i=0;i<str.size();i++)
		now=a[now].nex[str[i]-'a'],ans+=query(strt[now]);
	return ans;
}


int main()
{
	scanf("%d%d",&q,&n);
	for(int i=0;i<n;i++)scanf(" %s",&exx),s[i]=exx;
	build();
	dfs(0);
	for(int i=0;i<n;i++)update(strt[num[i]],fnsh[num[i]],1),mark[i]=1;
	while(q--)
	{
		char c;
		ll x;
		scanf(" %c",&c);
		if(c=='?')
		{
			scanf(" %s",&exx);str=exx;
			printf("%I64d\n",calc());
		}
		else
		{
			scanf("%d",&x);x--;
			if((c=='+' && mark[x]) || (c=='-' && !mark[x]))continue;
			mark[x]=!mark[x];
			update(strt[num[x]],fnsh[num[x]],(c=='+')?1:-1);
		}
	}
	return 0;
}