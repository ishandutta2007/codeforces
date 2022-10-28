#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n, k;
string s;
int f[26];
 
int32_t main()
{
	IOS;
	cin>>n>>k>>s;
	for(auto &it:s)
		f[it-'A']++;
	int ans=f[0];
	for(int i=0;i<k;i++)
		ans=min(ans, f[i]);
	ans*=k;
	cout<<ans;
	return 0;
}