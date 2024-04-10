#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, sum=0;
int a[N];
map<int, int> m;
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		m[a[i]]--;
		int cur=sum-a[i];
		if(cur%2==0)
		{
			if(m.find(cur/2)!=m.end() && m[cur/2]>0)
				v.push_back(i);
		}
		m[a[i]]++;
	}
	cout<<v.size()<<endl;
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}