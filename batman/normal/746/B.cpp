#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n;
string s;
char ans[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>s;
    ll k=n;
    for(int i=0;i<n;i++)ans[i]='.';
    for(int i=0;i<s.size();i++)
    {
    	ll x=(k-1)/2;
    	for(int j=0;j<n;j++)
    	{
    		if(x==0 && ans[j]=='.'){ans[j]=s[i];break;}
    		if(ans[j]=='.')x--;
		}
    	k--;
	}
	for(int i=0;i<n;i++)cout<<ans[i];
    return 0;
}