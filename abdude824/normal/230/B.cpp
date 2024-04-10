#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define fi(i,n) for(i=0;i<n;i++)
#define fr(i,n) for(i=n-1;i>=0;i--)
#define v(type) vector<type>
#define int long long
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x

void aeh()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
bool isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}
int32_t main()
{
	aeh();
	set<int>b;
	b.insert(4);
	for(int i=3;i<=1000000;i+=2)
	{
		if(isprime(i))
		{
			b.insert(i*i);
		}
	}
	int n;
	cin>>n;

	while(n--)
	{
		int x;cin>>x;
		if(b.find(x)!=b.end())
			cout<<"YES\n";
		else
			cout<<"NO\n";	
	}
	
}