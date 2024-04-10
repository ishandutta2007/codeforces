#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int w;
	cin>>w;
	if(w%2==0 && w>2)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;   
}