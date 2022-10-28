#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=305;

int n;
int a[N], b[N];
vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]==b[j])
			{
				for(int k=j;k>i;k--)
				{
					v.push_back({k-1, k});
					swap(b[k], b[k-1]);
				}
				break;
			}
		}
	}
	cout<<v.size()<<endl;
	for(auto it:v)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}