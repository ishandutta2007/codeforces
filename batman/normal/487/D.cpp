#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define M ((ll)11)
#define SQ ((ll)300)
#define INF ((ll)1e9)

ll n,m,q;
string s[N];
pair <ll,ll> ans[N][M];


void reset(ll x)	
{
	ll st[M],num=0;
	for(int i=0;i<m;i++)
	{
		if(s[x][i]=='<')
		{
			if(!i)ans[x][i]={x,-1};
			else if(s[x][i-1]=='>')
			{
				st[num++]=i;
				while(num)ans[x][st[--num]]={-2,-2};
			}
			else ans[x][i]=ans[x][i-1];
		}
		if(s[x][i]=='^')
		{
			pair <ll,ll> p={x-1,i};
			if(x%SQ)p=ans[x-1][i];
			st[num++]=i;
			while(num)ans[x][st[--num]]=p;
		}
		if(s[x][i]=='>')st[num++]=i;
	}
	while(num)ans[x][st[--num]]={x,m};
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	char exx[M];
	for(int i=0;i<n;i++)
	{
		scanf(" %s ",&exx);
		for(int j=0;j<m;j++)s[i]+=exx[j];
	}
	for(int i=0;i<n;i++)
		reset(i);
	while(q--)
	{
		char c,c2;
		ll x,y;
		scanf(" %c %d %d",&c,&x,&y);x--;y--;
		if(c=='A')
		{
			while(x>=0 && y>=0 && y<m)
			{
				ll ex=x;
				x=ans[x][y].first;
				y=ans[ex][y].second;
			}
			printf("%d %d\n",x+1,y+1);
		}
		else
		{
			scanf(" %c ",&c2);
			s[x][y]=c2;
			for(int i=x;i<min((x/SQ+1)*SQ,n);i++)
				reset(i);
		}
	}
    return 0;
}