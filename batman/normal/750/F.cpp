#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)200)

ll t,h,cnt;
vector <ll> e[N];
bool mark[N];

bool ask(ll x)
{
	if(mark[x])return 0;
	if(cnt==16)return 1;
	mark[x]=1;cnt++;
	cout<<"? "<<x<<endl;
	ll num,y;
	cin>>num;
	for(int i=0;i<num;i++)cin>>y,e[x].push_back(y);
	return num==2;
}

int main()
{
	cin>>t;
	while(t--)
	{
		bool flg=0;
		cnt=0;
		memset(mark,0,sizeof mark);
		for(int i=0;i<N;i++)e[i].clear();
		cin>>h;
		if(ask(1)){cout<<"! 1"<<endl;continue;}
		ll lst=0,now=1;
		vector <ll> path1,path2;
		while(1)
		{
			path1.push_back(now);
			if(e[now].size()==1)break;
			ll u=e[now][0];
			if(u==lst)u=e[now][1];
			if(ask(u)){cout<<"! "<<u<<endl;flg=1;break;}
			lst=now;now=u;
		}
		if(flg)continue;
		lst=0,now=1;
		while(1)
		{
			path2.push_back(now);
			if(e[now].size()==1)break;
			ll u=e[now][1];
			if(u==lst)u=e[now][0];
			if(ask(u)){cout<<"! "<<u<<endl;flg=1;break;}
			lst=now;now=u;
		}
		if(flg)continue;
		reverse(path1.begin(),path1.end());path1.pop_back();
		ll dis=((ll)path1.size()+(ll)path2.size()),v;
		if(dis/2<(ll)path1.size())v=path1[dis/2];
		else v=path2[dis/2-(ll)path1.size()];
		ll now_h=dis/2+1,nex_v;
		if(v==1)
		{
			if(e[v].size()==1)nex_v=e[v][0];
			else nex_v=e[v][2];
		}
		else
		{
			path1.push_back(1);
			for(int i=1;i<(ll)path1.size()-1;i++)
				if(path1[i]==v)
				{
					nex_v=e[v][0];
					if(nex_v==path1[i-1] || nex_v==path1[i+1])nex_v=e[v][1];
					if(nex_v==path1[i-1] || nex_v==path1[i+1])nex_v=e[v][2];
				}
			for(int i=1;i<(ll)path2.size()-1;i++)
				if(path2[i]==v)
				{
					nex_v=e[v][0];
					if(nex_v==path2[i-1] || nex_v==path2[i+1])nex_v=e[v][1];
					if(nex_v==path2[i-1] || nex_v==path2[i+1])nex_v=e[v][2];
				}
		}
		while(now_h<h-3)
		{
			vector <ll> path;
			lst=v,now=nex_v;
			if(ask(nex_v)){cout<<"! "<<nex_v<<endl;flg=1;break;}
			while(1)
			{
				path.push_back(now);
				if(e[now].size()==1)break;
				ll u=e[now][0];
				if(u==lst)u=e[now][1];
				if(ask(u)){cout<<"! "<<u<<endl;flg=1;break;}
				lst=now;now=u;
			}
			if(flg)break;
			ll ex=((ll)path.size()-now_h)/2;
			if(ex==0)
			{
				ll tmp=nex_v;
				nex_v=e[tmp][0];
				if(nex_v==path[1] || nex_v==v)nex_v=e[tmp][1];
				if(nex_v==path[1] || nex_v==v)nex_v=e[tmp][2];
				v=tmp;
			}
			else
			{
				v=path[ex];
				nex_v=e[v][0];
				if(nex_v==path[ex-1] || nex_v==path[ex+1])nex_v=e[v][1];
				if(nex_v==path[ex-1] || nex_v==path[ex+1])nex_v=e[v][2];
			}
			now_h+=ex+1;
		}
		if(flg)continue;
		if(ask(nex_v)){cout<<"! "<<nex_v<<endl;continue;}
		for(auto u:e[nex_v])
		{
			if(u==v)continue;
			if(ask(u)){cout<<"! "<<u<<endl;break;}
			for(auto p:e[u])
				if(ask(p))
				{
					cout<<"! "<<p<<endl;
					flg=1;
					break;
				}
			if(flg)break;
		}
	}
	return 0;
}