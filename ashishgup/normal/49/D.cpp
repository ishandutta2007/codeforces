#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, ans1=0, ans2=0;
string s;

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		ans1+=((s[i]-'0')!=(i&1));
		ans2+=((s[i]-'0')==(i&1));
	}
	cout<<min(ans1, ans2);
	return 0;
}