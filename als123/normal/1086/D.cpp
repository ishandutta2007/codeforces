#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const int N=200005;
int n,q; 
char ss[N];
int get (char x)
{
	if (x=='R') return 0;
	if (x=='P') return 1;
	if (x=='S') return 2;
}
int win (int x)
{
	if (x==0) return 2;
	if (x==1) return 0;
	if (x==2) return 1;
}
int lose (int x)
{
	if (x==0) return 1;
	if (x==1) return 2;
	if (x==2) return 0;
}
int f[3][N];//
set<int> s[N];
int lb (int x)	{return x&(-x);}
void add (int o,int x,int xx)	
{
	if (xx==-1) s[o].erase(x);
	else s[o].insert(x);
	while (x<=n){f[o][x]+=xx;x+=lb(x);}
}
int query (int o,int x)	{int lalal=0;while (x>=1) {lalal+=f[o][x];x-=lb(x);}return lalal;}
void solve ()
{
	int ans=0;
	for (int u=0;u<=2;u++)// 
	{
		int x=win(u),y=lose(u);
		int L,R,LL,RR;
		//[1,R]     [L,n] 
		if (!s[y].empty()) R=(*s[y].begin());
		else R=n;
		if (!s[x].empty()) L=(*s[x].begin());
		else L=n+1;
		//[1,R]   [LL,n] 
		if (!s[y].empty()) LL=*(--s[y].end());
		else LL=1;
		if (!s[x].empty()) RR=*(--s[x].end());
		else RR=0;
		//printf("%d %d %d %d %d\n",u,L,R,LL,RR);
		if (L+1<=R&&LL+1<=RR)	ans=ans+query(u,n);
		else if (L+1<=R)
		{
			ans=ans+query(u,n)-query(u,LL-1)+query(u,RR);
		}
		else if (LL+1<=RR)
		{
			ans=ans+query(u,n)-query(u,L-1)+query(u,R);
		}
		else
		{
			swap(L,R);swap(LL,RR);
			L++;R--;
			LL++;RR--;
			//printf("%d %d %d %d\n",L,R,LL,RR);
			ans=ans+query(u,n);
			if (L>LL)	{swap(L,LL);swap(R,RR);}
			ans=ans-(query(u,R)-query(u,L-1));
			if (R<=RR) ans=ans-(query(u,RR)-query(u,max(LL-1,R)));
		}
		//printf("YES:%d\n",ans);
	}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",ss+1);
	for (int u=1;u<=n;u++)
	{
		int t=get(ss[u]);
		add(t,u,1);
	}
	solve();
	while (q--)
	{
		int x,t;
		scanf("%d",&x);
		char ch=getchar();
		while (ch!='R'&&ch!='S'&&ch!='P') ch=getchar();
		t=get(ss[x]);add(t,x,-1);
		ss[x]=ch;
		t=get(ss[x]);add(t,x,1);
		solve();
	}
	return 0;
}