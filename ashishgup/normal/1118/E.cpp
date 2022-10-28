#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int n, k;
	cin>>n>>k;
	int mx=k*(k-1);
	if(n>mx)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	int u=0, v=1;
	for(int i=1;i<=n/2;i++)
	{
		int colu=u+1;
		int colv=v+1;
		cout<<colu<<" "<<colv<<endl;
		cout<<colv<<" "<<colu<<endl;
		v++;
		v%=k;
		if(v==0)
		{
			u++;
			v=u+1;
		}
	}
	if(n%2)
		cout<<u+1<<" "<<v+1;
	return 0;
}