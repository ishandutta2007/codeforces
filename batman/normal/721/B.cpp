#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)5050)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,k,num,ti,p;
string s[N],t;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>t;
	for(int i=0;i<n;i++)
	{
		if((ll)s[i].size()<(ll)t.size())
		{
			num++;ti++;
		if(num==k)ti+=5,num=0;
		}
		if((ll)s[i].size()==(ll)t.size())p++;
	}
	cout<<ti+1<<" ";
	for(int i=0;i<p-1;i++)
	{
		num++;ti++;
		if(num==k)ti+=5,num=0;
	}
	cout<<ti+1;
	return 0;
}