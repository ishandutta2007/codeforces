#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
string a, b;
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		bool check=0;
		for(int j=i;j<n;j++)
		{
			if(b[i]==a[j])
			{
				check=1;
				for(int k=j-1;k>=i;k--)
				{
					v.push_back(k);
					swap(a[k], a[k+1]);
				}
				break;
			}
		}
		if(!check)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<v.size()<<endl;
	for(auto it:v)
		cout<<it+1<<" ";
	return 0;
}