#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n;
vector <ll> res;
bool sad,yekan,dahgan;
ll jaghool=-1;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		if(x==0){res.push_back(0);continue;}
		if(x==100 && !sad){sad=1;res.push_back(100);continue;}
		else if(x==100 && sad)continue;
		if(x<10 && !yekan){yekan=1;res.push_back(x);continue;}
		else if(x<10 && yekan)continue;
		if(x%10==0 && !dahgan){dahgan=1;res.push_back(x);continue;}
		else if(x%10==0 && dahgan)continue;
		jaghool=x;
	}
	if(!yekan && !dahgan && jaghool!=-1)res.push_back(jaghool);
	cout<<res.size()<<"\n";
	for(auto u:res)cout<<u<<" ";
	return 0;
}