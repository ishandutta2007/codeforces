#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	
	int a=0;
	int ans=1;
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		
		(i!=0 && abs(a-t)<=m)?ans++:ans=1;
		a=t;
	}
	cout << ans << endl;
	
	return 0;
}