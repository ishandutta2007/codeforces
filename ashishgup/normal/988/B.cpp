#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
string a[N];

bool comp(string &s1, string &s2)
{
	int sz1=s1.size();
	int sz2=s2.size();
	if(sz1!=sz2)
		return sz1<sz2;
	return s1<s2;
}

bool check(string &s1, string &s2)
{
	if(s2.find(s1)==string::npos)
		return 0;
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1, comp);
	for(int i=1;i<=n-1;i++)
	{
		if(!check(a[i], a[i+1]))
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<endl;
	return 0;
}