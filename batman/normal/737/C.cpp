#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,s;
ll base_ans,empty,sum=1,ans=INF,num[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n>>s;
   	for(int i=0;i<n;i++)
   	{
   		ll x;
   		cin>>x;
   		if(i+1==s && x!=0)base_ans++,x=0;
   		num[x]++;
	}
	if(n==1)return cout<<base_ans,0;
	for(int i=1;i<n;i++)
	{
		if(!num[i])empty++;
		sum+=num[i];
		ans=min(ans,base_ans+max(empty,(n-sum)));
	}
	cout<<ans;
	return 0;
}