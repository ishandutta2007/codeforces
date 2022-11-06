#include<bits/stdc++.h>
using namespace std;
long long a,b,c,T,d[1000001],v[1000001],o,h[500001],u[1000001],cn,ans,an,fl;
string s;
struct p
{
	long long q,w;
}l[1000001];
void add(long long qq,long long ww)
{
	l[++o].q=ww;
	l[o].w=h[qq];
	h[qq]=o;
}
bool ch(long long qq)
{
	cn=0;
	for(int i=1;i<=a;i++)
	{
		if(d[i]<=qq)
		{
			u[++cn]=d[i];
		}
	}
	long long an=0;
	for(int i=1;i<=cn;i++)
	{
		long long tt=0;
		for(int j=i;j<i+b&&j<=cn;j++)
		{
			an+=u[j];tt+=u[j];
			if(an>c) return false;
		}
		an+=tt;
		i=i+b-1;
	}
	return true;
}
priority_queue<long long> qu[4];
priority_queue<long long,vector<long long>,greater<long long> > yy;
int main()
{
	T=1;
//	scanf("%lld",&T);
	for(int ii=1;ii<=T;ii++)
	{
		scanf("%lld",&a);
		for(int i=1;i<=a;i++)
		{
			cin>>s;
			if(s[0]=='0'&&s[1]=='0') l[i].q=0;
			else if(s[0]=='0'&&s[1]=='1') l[i].q=1;
			else if(s[0]=='1'&&s[1]=='0') l[i].q=2;
			else l[i].q=3;scanf("%lld",&l[i].w);
			qu[l[i].q].push(l[i].w);
		}
		while(!qu[0].empty()&&!qu[3].empty())
		{
			an+=qu[0].top()+qu[3].top();
			yy.push(qu[0].top());
			qu[0].pop();qu[3].pop();
		}
		while(!qu[1].empty()&&!qu[2].empty())
		{
			an+=qu[1].top()+qu[2].top();
			qu[1].pop();qu[2].pop();
		}
		while(!qu[3].empty()&&!qu[1].empty())
		{
			an+=qu[3].top()+qu[1].top();
			qu[3].pop();qu[1].pop();
		}
		while(!qu[3].empty()&&!qu[2].empty())
		{
			an+=qu[3].top()+qu[2].top();
			qu[3].pop();qu[2].pop();
		}
		while(!qu[3].empty())
		{
			an+=qu[3].top();
			qu[3].pop();
		}
		while(!qu[1].empty()&&!yy.empty())
		{
			if(qu[1].top()>yy.top())
			{
				an+=qu[1].top()-yy.top();yy.pop();
				yy.push(qu[1].top());
				qu[1].pop();
			}
			else break;
		}
		while(!qu[2].empty()&&!yy.empty())
		{
			if(qu[2].top()>yy.top())
			{
				an+=qu[2].top()-yy.top();yy.pop();
				yy.push(qu[2].top());qu[2].pop();
			}
			else break;
		}
		printf("%lld",an);
	}
	return 0;
}