#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
map<string, string> ans;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string a, b;
		cin>>a>>b;
		b+=";";
		ans[b]=a;
	}
	for(int i=1;i<=m;i++)
	{
		string a, b;
		cin>>a>>b;
		cout<<a<<" "<<b<<" #"<<ans[b]<<endl;
	}
	return 0;
}