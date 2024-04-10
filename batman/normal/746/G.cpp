#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)201*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,t,k,a[N],num=2,par[N],res;
vector <ll> leaf[N],all[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>t>>k;
    for(int i=1;i<=t;i++)
    {
    	cin>>a[i];
    	ll now_par=num-1;
    	for(int j=0;j<a[i];j++)
		{
			if(j!=a[i]-1 || i==t)leaf[i].push_back(num),res++;
			all[i].push_back(num);
			par[num++]=now_par;
		}
	}
	if(res<k)return cout<<-1,0;
	for(int i=t;i>=2;i--)
	{
		while(res!=k && (ll)all[i].size()>1 && (ll)leaf[i-1].size())
		{
			par[all[i].back()]=leaf[i-1].back();
			all[i].pop_back();leaf[i-1].pop_back();
			res--;
		}
	}
	if(res!=k)return cout<<-1,0;
	cout<<n<<"\n";
	for(int i=2;i<=n;i++)
		cout<<par[i]<<" "<<i<<"\n";
    return 0;
}