#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)301*1000)
#define INF ((ll)2e9+100)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n;
vector <string> s[4];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string p,q;
		cin>>p>>q;
		if(q=="rat")s[0].push_back(p);
		if(q=="child" || q=="woman")s[1].push_back(p);
		if(q=="man")s[2].push_back(p);
		if(q=="captain")s[3].push_back(p);
	}
	for(int i=0;i<4;i++)for(auto u:s[i])cout<<u<<"\n";
	return 0;
}