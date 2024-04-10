#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, cur=0;
int a[N];
vector<int> v;
set<int> s;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	v.push_back(0);
	for(auto &it:s)
		v.push_back(it);
	for(int i=1;i<v.size() && k>0;k--, i++)
		cout<<v[i]-v[i-1]<<endl;
	for(int i=1;i<=k;i++)
		cout<<0<<endl;
	return 0;
}