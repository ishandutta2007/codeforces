#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, changes=1e9;
string s, ans;
map<char, int> m[3];

int32_t main()
{
	IOS;
	cin>>n>>s;
	vector<char> pos={'B', 'G', 'R'};
	do
	{
		int cur=0;
		for(int i=0;i<=min(2LL, 1LL*s.size());i++)
		{
			for(int j=i;j<s.size();j+=3)
				if(s[j]!=pos[i])
					cur++;
		}
		if(cur<changes)
		{
			changes=cur;
			ans="";
			for(int i=0;i<s.size();i++)
				ans+=pos[i%3];
		}
	}while(next_permutation(pos.begin(), pos.end()));
	cout<<changes<<endl;
	cout<<ans;
	return 0;
}