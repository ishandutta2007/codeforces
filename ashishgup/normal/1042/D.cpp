#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=2e5+5;

#define T pair<int, int>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

int getless(ordered_set &os, int R, int index)
{
	return os.order_of_key({R, index});
}

ordered_set os1;
int n, t, idx=1, ans=0;
int a[N], pref[N];

int32_t main()
{
	IOS;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]+a[i];
	}
	os1.insert({0, 0});
	for(int i=1;i<=n;i++)
	{
		ans+=os1.size()-getless(os1, pref[i]-t, 1e9);
		os1.insert({pref[i], ++idx});
	}
	cout<<ans;
	return 0;
}