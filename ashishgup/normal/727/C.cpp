#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int N=1e6+5;

int n, a, b, c;
int ans[N];

int32_t main()
{
	cin>>n;
	cout<<"? "<<1<<" "<<2<<endl;
	cin>>a;
	cout<<"? "<<2<<" "<<3<<endl;
	cin>>b;
	cout<<"? "<<1<<" "<<3<<endl;
	cin>>c;
	ans[1]=((a+b+c) - 2*b)/2;
	ans[2]=((a+b+c) - 2*c)/2;
	ans[3]=((a+b+c) - 2*a)/2;
	for(int i=4;i<=n;i++)
	{
		cout<<"? "<<1<<" "<<i<<endl;
		cin>>ans[i];
		ans[i]-=ans[1];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}