#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, sum=0;
int a[N];

int32_t main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		int remsum=sum-a[i];
		if(remsum%(n-1)==0)
		{
			if((remsum/(n-1)) == a[i])
				v.push_back(i);
		}
	}
	cout<<v.size()<<endl;
	for(auto it:v)
		cout<<it<<" ";
	return 0;
}