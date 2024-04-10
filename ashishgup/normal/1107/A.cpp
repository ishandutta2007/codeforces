#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=305;

int n;
char a[N];

int32_t main()
{
	IOS;
	int q;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)	
			cin>>a[i];
		if(n==2 && a[1]>=a[2])
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		cout<<2<<endl;
		cout<<a[1]<<" ";
		for(int i=2;i<=n;i++)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}