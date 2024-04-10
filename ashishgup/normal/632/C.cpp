#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
string a[N];

bool comp(string &a, string &b)
{
	string p=a+b;
	string q=b+a;
	return p<q;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1, comp);
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}