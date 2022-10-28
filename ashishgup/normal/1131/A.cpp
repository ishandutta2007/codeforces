#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int w1, h1, w2, h2;
	cin>>w1>>h1>>w2>>h2;
	int ans=w1 + 2 + h1*2;
	ans+=w2 + 2 + h2*2;
	ans+=w1-w2;
	cout<<ans;
	return 0;
}