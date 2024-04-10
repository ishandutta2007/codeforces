#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,a[N];

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		string s="";
		getline(cin,s);
		ll num=0;
		for(int j=0;j<s.size();j++)if(s[j]=='a' || s[j]=='e' || s[j]=='u' || s[j]=='o' || s[j]=='y' || s[j]=='i')a[i]--,num++;
		if(a[i]!=0)
		{
			cout<<"NO";
			exit(0);
		}
	}
	cout<<"YES";
	return 0;
}