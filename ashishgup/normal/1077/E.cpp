#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
int a[N];
map<int, int> m;
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	for(auto &it:m)
		v.push_back(it.second);
	sort(v.begin(), v.end());
	for(int i=1;i<=2e5;i++)
	{
		auto it=lower_bound(v.begin(), v.end(), i);
		if(it!=v.end())
		{
			int cur=i;
			int nxt=cur*2;
			int idx=it-v.begin();
			while(lower_bound(v.begin()+idx+1, v.end(), nxt)!=v.end())
			{
				cur+=nxt;
				idx=lower_bound(v.begin()+idx+1, v.end(), nxt)-v.begin();
				nxt=nxt*2;
			}
			ans=max(ans, cur);
		}
	}
	cout<<ans;
	return 0;
}