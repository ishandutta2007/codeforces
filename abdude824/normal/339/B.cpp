#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fr(n) for(int i=n-1;i>=0;i--)
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




int32_t main()
{
	aeh();
	int n,m;cin>>n>>m;
	int a[m];
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	int p=0;
	p+=a[0]-1;
	for(int i=0;i<m-1;i++)
	{
		if(a[i+1]<a[i])
			p+=n-a[i]+a[i+1];
		else 
			p+=a[i+1]-a[i];
	}
	cout<<p<<endl;
}