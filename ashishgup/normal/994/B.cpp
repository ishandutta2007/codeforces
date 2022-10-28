#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

struct data
{
	int p, c, idx;
};

bool comp(struct data &d1, struct data &d2)
{
	return d1.p < d2.p;
}

int n, k;
int ans[N];
struct data a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p;
		a[i].idx=i;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i].c;
	sort(a+1, a+n+1, comp);
	multiset<int> m;
	for(int i=1;i<=n;i++)
	{
		ans[a[i].idx]=a[i].c;
		int ct=k;
		auto it=m.end();
		while(ct>0)
		{
			if(it==m.begin())
				break;
			ct--;
			--it;
			ans[a[i].idx]+=*it;
		}
		m.insert(a[i].c);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}