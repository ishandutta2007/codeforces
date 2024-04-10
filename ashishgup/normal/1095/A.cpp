#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
string s;

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=0,j=1;i<n;i+=j,j++)
		cout<<s[i];
	return 0;
}