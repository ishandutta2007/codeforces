#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0, cur=0;
string s;
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n>>s;
	m[0]=-1;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
			cur++;
		else
			cur--;
		if(m.find(cur)!=m.end())
			ans=max(ans, i-m[cur]);		
		else
			m[cur]=i;
	}		
	cout<<ans;
	return 0;
}