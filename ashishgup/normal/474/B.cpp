#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m;
int a[N];
set<pair<int, int> > s;

int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
		pair<int, int> p={a[i], i};
		s.insert(p);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		pair<int, int> p={k, 0};
		auto it=s.lower_bound(p);
		cout<<it->second<<endl;
	}
	return 0;
}