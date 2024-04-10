#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e6+5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		map<int, int> m;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			m[a[i]]++;
		}
		vector<int> v;
		vector<int> ans;
		for(auto &it:m)
		{
			if(it.second>=2)
				v.push_back(it.first);
			if(it.second>=4)
			{
				ans.push_back(it.first);
				break;
			}
		}
		if(ans.size())
		{
			for(int i=1;i<=4;i++)
				cout<<ans[0]<<" ";
			cout<<endl;
			continue;
		}
		int l=-1, r=-1;
		double val=1e18;
		for(int i=0;i+1<v.size();i++)
		{
			double a=v[i], b=v[i+1];
			double curval=(2*a+2*b)*(2*a+2*b)/(a*b);
			if(curval<val)
			{
				val=curval;
				l=v[i], r=v[i+1];
			}
		}
		cout<<l<<" "<<l<<" "<<r<<" "<<r<<endl;
	}
	return 0;
}