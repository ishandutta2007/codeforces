#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int ans=1;
vector<int> ways={2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int32_t main()
{
	IOS;
	char ch;
	while(cin>>ch)
		ans*=ways[ch-'0'];
	cout<<ans;
	return 0;
}