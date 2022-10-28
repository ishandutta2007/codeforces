#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
string s;
map<char, int> m;

int32_t main()
{
	IOS;
	cin>>n>>s;
	if(n==1)
	{
		cout<<"Yes";
		return 0;
	}
	for(auto &it:s)
		m[it]++;
	int check=0;
	for(auto &it:m)
		check|=(it.second>=2);
	if(check)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}