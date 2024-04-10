#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int f[N];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int l, r;
		cin>>l>>r;
		f[l]+=1;
		f[r+1]-=1;
	}
	for(int i=1;i<=m;i++)
	{
		f[i]+=f[i-1];
		if(!f[i])
			v.push_back(i);
	}
	cout<<v.size()<<endl;
	for(auto it:v)
		cout<<it<<" ";
	return 0;
}