#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, sum=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%k)
	{
		cout<<"No";
		return 0;
	}
	int reqd=sum/k;
	int cur=0, cnt=0;
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		cur+=a[i];
		cnt++;
		if(cur==reqd)
		{
			v.push_back(cnt);
			cnt=0;
			cur=0;
		}
		else if(cur>reqd)
		{
			cout<<"No";
			return 0;
		}
	}
	if(cur>0)
	{
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<endl;
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}