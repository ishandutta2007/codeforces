#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)5050)
#define K ((ll)3001*1000)

char s[K];
ll k,n,l[N],r[N];
vector <deque <char> > vec;

void solve(ll x,ll len)
{
	if(x==-1)
	{
		deque <char> ex;
		for(int i=0;i<len;i++)ex.push_back(s[i]);
		vec.push_back(ex);
		return ;
	}
	if(r[x]>=len)
	{
		solve(x-1,len);
		return ;
	}
	ll now_len=min(len-r[x]-1,r[x]-l[x]+1);
	solve(x-1,len-now_len);
	deque <char> res;
	ll fnsh=-1,cut=0;
	for(int pp=0;pp<2;pp++)
	{
		ll now=0,pos=l[x]+1-pp;
		for(int i=0;i<vec.size();i++)
		{
			now+=vec[i].size();
			if(now>r[x] && fnsh==-1)fnsh=i,cut=now-r[x]-1;
			if(now<=pos)continue;
			now-=vec[i].size();
			for(int j=pos-now;res.size()<now_len && j<vec[i].size() && j<=r[x]-now;j+=2)
				res.push_back(vec[i][j]),pos+=2;
			now+=vec[i].size();
		}
	}
	if(cut>(ll)vec[fnsh].size()/2)
	{
		deque <char> ex;
		while(vec[fnsh].size()>cut)ex.push_back(vec[fnsh].front()),vec[fnsh].pop_front();
		vec.insert(vec.begin()+fnsh,ex);
	}
	else
	{
		deque <char> ex;
		while(ex.size()<cut)ex.push_front(vec[fnsh].back()),vec[fnsh].pop_back();
		vec.insert(vec.begin()+fnsh+1,ex);
	}
	vec.insert(vec.begin()+fnsh+1,res);
}

int main()
{
	scanf("%s",s);
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;i++)scanf("%d%d",&l[i],&r[i]),l[i]--,r[i]--;
	solve(n-1,k);
	for(auto u:vec)
		for(auto w:u)
			printf("%c",w);
	return 0;
}