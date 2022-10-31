#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll int
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll MOD=((ll)81671);
const ll N=((ll)40);
const ll M=((ll)12);
const ll X=((ll)2e6);

ll n,m,p[M];
string s[M],now;
bool mark[X];
vector <string> v;

void solve(ll pos,ll x)
{
	if(x<0)return ;
	if(pos==(ll)s[0].size() && x!=0)return ;
	if(x==0)
	{
		for(int i=pos;i<s[0].size();i++)now[i]=(s[0][i]=='0')?'1':'0';
		v.push_back(now);
		return ;
	}
	now[pos]=s[0][pos];
	solve(pos+1,x-1);
	now[pos]=(s[0][pos]=='0')?'1':'0';
	solve(pos+1,x);
	now[pos]=s[0][pos];
}

int main()
{
	cin>>n>>m>>s[0]>>p[0];
	now=s[0];
	solve(0,p[0]);
	ll ans=v.size();
	for(int i=1;i<m;i++)
	{
		cin>>s[i]>>p[i];
		for(int j=0;j<v.size();j++)
			if(!mark[j])
			{
				ll num=0;
				for(int k=0;k<v[j].size();k++)
					if(v[j][k]==s[i][k])
						num++;
				if(num!=p[i])mark[j]=1,ans--;
			}
	}
	cout<<ans;
    return 0;
}