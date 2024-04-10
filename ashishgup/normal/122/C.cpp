#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

set<int> st;

void dfs(string s)
{
	if(s.size()>10)
		return;
	int num=stoll(s);
	st.insert(num);
	dfs(s+"4");
	dfs(s+"7");
}
	
int32_t main()
{
	dfs("4");
	dfs("7");
	int l, r;
	cin>>l>>r;
	int ans=0;
	for(int i=l;i<=r;i++)
	{
		int next=*(st.lower_bound(i));
		ans+=(min(r,next)-i+1)*next;
		i=next;
	}
	cout<<ans;
	return 0;
}