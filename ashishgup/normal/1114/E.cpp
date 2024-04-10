#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N=1e6+5;

int n, queries=60;
int indices[N], a[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> v;

int query1(int i)
{
	cout<<"? "<<i<<endl;
	int x;
	cin>>x;
	return x; 
}

int query2(int x)
{
	queries--;
	cout<<"> "<<x<<endl;
	int val;
	cin>>val;
	return val;
}

void output(int x, int d)
{
	cout<<"! "<<x<<" "<<d<<endl;
	exit(0);
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(query2(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n;
	int mx=binsearch(0, 1e9) + 1;
	for(int i=1;i<=n;i++)
		indices[i]=i;
	shuffle(indices+1, indices+n+1, rng);
	for(int i=1;i<=min(n, queries);i++)
	{
		int idx=indices[i];
		a[idx]=query1(idx);
		v.push_back(a[idx]);
	}
	sort(v.begin(), v.end());
	int ans=v[0];
	int diff=v[1]-v[0];
	int sz=v.size();
	for(int i=0;i<sz;i++)
		for(int j=i+1;j<sz;j++)
			diff=__gcd(diff, v[j]-v[i]);
	ans=min(ans, mx - (n-1)*diff);
	output(ans, diff);
	return 0;	
}