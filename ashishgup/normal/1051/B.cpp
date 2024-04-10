#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int l, r;
	cin>>l>>r;
	cout<<"YES"<<endl;
	for(int i=l;i<=r;i+=2)
		cout<<i<<" "<<i+1<<endl;
	return 0;
}