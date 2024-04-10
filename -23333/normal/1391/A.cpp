#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
int main()
{
	int n;
	cin>>n;
	rep(i,1,n)
	{
		int x;
		cin>>x;
		rep(i,1,x) cout<<i<<" ";
		cout<<endl;
	}
	
	return 0;
}