#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int a, b;
	cin>>a>>b;
	int tot=a+b;
	int ans=0;
	for(int i=1;;i++)
	{
		int cur=i*(i+1)/2;
		if(cur>tot)
			break;
		ans=i;
	}
	vector<int> v1, v2;
	for(int i=ans;i>=1;i--)
	{
		if(a-i>=0)
		{
			a-=i;
			v1.push_back(i);
		}
		else if(b-i>=0)
		{
			b-=i;
			v2.push_back(i);
		}
	}
	cout<<v1.size()<<endl;
	for(auto &it:v1)
		cout<<it<<" ";
	cout<<endl;
	cout<<v2.size()<<endl;
	for(auto &it:v2)
		cout<<it<<" ";
	cout<<endl;
	return 0;
}