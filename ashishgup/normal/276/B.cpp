#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	map<char, int> m;
	for(auto &it:s)
		m[it]++;
	int odd=0;
	for(auto &it:m)
		odd+=(it.second%2);
	int diff=(odd-1);
	if(diff%2==0 || diff==-1)
		cout<<"First";
	else
		cout<<"Second";
	return 0;
}