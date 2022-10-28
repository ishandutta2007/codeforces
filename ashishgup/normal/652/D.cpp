#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

const int N=2e5+5;

struct data
{
	int l, r, ind;
};

bool comp(struct data &d1, struct data &d2)
{
	return d1.l<d2.l;
};

int getless(ordered_set & os, int k)
{
	return os.order_of_key(k);
}

ordered_set os;
int n;
int ans[N];
struct data a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].r;
		a[i].ind=i;
	}
	sort(a+1, a+n+1, comp);
	for(int i=n;i>=1;i--)
	{
		os.insert(a[i].r);
	}
	for(int i=1;i<=n;i++)
	{
		ans[a[i].ind]=getless(os, a[i].r);
		os.erase(a[i].r);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}