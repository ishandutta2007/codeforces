#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	string s;
	cin>>s;
	int a=0, d=0;
	for(auto it:s)
		a+=(it=='A'), d+=(it=='D');
	if(a>d)
		cout<<"Anton";
	else if(a==d)
		cout<<"Friendship";
	else
		cout<<"Danik";
	return 0;
}