#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n, a, b;
	cin>>n>>a>>b;
	for(int x=0;x<=n;x++)
	{
		int p=x*a;
		int q=n-p;
		if(q<0)
			continue;
		if(q%b!=0)
			continue;
		cout<<"YES"<<endl;
		cout<<x<<" "<<q/b;
		return 0;
	}
	cout<<"NO";
   	return 0;
}