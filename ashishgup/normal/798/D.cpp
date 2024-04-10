#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define pb push_back

const int N=1e5+5;

int n;
int a[N], b[N];
pair<int, int> c[N];
vector<int> ans;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i].ff=a[i];
		c[i].ss=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(c+1, c+n+1);
	reverse(c+1, c+n+1);
	ans.pb(c[1].ss);
	for(int i=2;i<=n;i+=2)
	{
		int cur=c[i].ss;
		if(i+1<=n && b[c[i+1].ss]>b[cur])
			cur=c[i+1].ss;
		ans.pb(cur);
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
}