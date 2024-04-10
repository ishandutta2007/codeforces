#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int k;
string s;
set<char> st;

int32_t main()
{
	IOS;
	cin>>s;
	cin>>k;
	for(auto &it:s)
		st.insert(it);
	if(k>s.size())
	{
		cout<<"impossible";
		return 0;
	}
	int ans=max(0LL, k-st.size());
	cout<<ans;
	return 0;
}