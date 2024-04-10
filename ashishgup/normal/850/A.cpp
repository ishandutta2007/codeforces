#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, ans=0;
int a[N][10];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n;
	if(n>100)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		bool check=1;
		for(int j=1;j<=n;j++)
		{
			if(j==i)
				continue;
			for(int k=1;k<=n;k++)
			{
				if(i==k || j==k)
					continue;
				int dot=0;
				for(int cap=1;cap<=5;cap++)
					dot+=(a[j][cap]-a[i][cap])*(a[k][cap]-a[i][cap]);
				check&=(dot<=0);
			}
		}
		if(check)
			v.push_back(i);
	}
	cout<<v.size()<<endl;
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}