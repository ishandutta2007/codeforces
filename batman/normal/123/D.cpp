#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)20)

string s;
int n,pos[K][N],a[N],b[N],lft[N];
pair <pair<int,int>,int> tmp[N];
map <string,ll> mp;
ll ans2;

bool cmp(ll x,ll y){return pos[K-1][x]<pos[K-1][y];}

ll lcp(ll x,ll y)
{
	ll res=0;
	for(int i=K-1;x<n && y<n && i>=0;i--)
		if(pos[i][x]==pos[i][y])
			x+=(1<<i),y+=(1<<i),res+=(1<<i);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)pos[0][i]=(s[i]-'a'),a[i]=i;
	for(int i=1;i<K;i++)
	{
		for(int j=0;j<n;j++)
		{
			tmp[j]={{pos[i-1][j],-1},j};
			if(j+(1<<(i-1))<n)tmp[j].first.second=pos[i-1][j+(1<<(i-1))];
		}
		sort(tmp,tmp+n);
		for(int j=0,now=0;j<n;j++)
		{
			if(j && tmp[j].first!=tmp[j-1].first)now++;
			pos[i][tmp[j].second]=now;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n-1;i++)b[i]=lcp(a[i],a[i+1]);
	ll ans=1LL*n*(n+1)/2;
	stack <ll> st;
	for(int i=0;i<n-1;i++)
	{
		while(st.size() && b[st.top()]>=b[i])st.pop();
		lft[i]=-1;
		if(st.size())lft[i]=st.top();
		st.push(i);
	}
	while(st.size())st.pop();
	for(int i=n-2;i>=0;i--)
	{
		while(st.size() && b[st.top()]>b[i])st.pop();
		ll rght=n-1;
		if(st.size())rght=st.top();
		st.push(i);
		ans+=1LL*b[i]*(rght-i)*(i-lft[i]);
	}
	cout<<ans;
	return 0;
}