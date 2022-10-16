#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll n,x[100005],dp[100005],sum,pd[100005];
vector <ll> d[100005];
queue <ll> q[100005],g[100005];
map <ll,ll> t[100005];
void dfs(ll pos,ll f)
{
	pd[pos]=1;
	q[pos].push(x[pos]),t[pos][x[pos]]++;
	while(q[f].size()){
		ll val=q[f].front();
		g[f].push(val);
		ll k=gcd(val,x[pos]);
		ll num=t[f][val];
		if(!t[pos][k])q[pos].push(k);
		t[pos][k]+=num;
//		cout<<val<<" "<<num<<endl;
		sum=(sum+num*k)%mod;
		q[f].pop();
	}
	while(g[f].size())q[f].push(g[f].front()),g[f].pop();
//	cout<<pos<<" "<<sum<<endl;
	for(int i=0;i<d[pos].size();i++)
		if(!pd[d[pos][i]])
			dfs(d[pos][i],pos);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i],sum=(sum+x[i])%mod;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		d[u].push_back(v);
		d[v].push_back(u);
	}
	dfs(1,0);
	cout<<sum;
    return 0;
}