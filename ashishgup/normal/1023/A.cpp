#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
string a, b;

int32_t main()
{
	IOS;
	cin>>n>>m;
	cin>>a>>b;
	int i=0, j=0;
	while(i<n && j<m && a[i]==b[j])
	{
		i++;
		j++;
	}
	if(j==m&&i==n)
	{
		cout<<"YES";
		return 0;
	}
	if(i==n)
	{
		cout<<"NO";
		return 0;
	}
	int i2=n-1, j2=m-1;
	while(i2>=0 && j2>=0 && a[i2]==b[j2])
	{
		i2--;
		j2--;
	}
	if(i2<i||i2>i||j2<j-1)
	{
		cout<<"NO";
		return 0;
	}
	if(a[i]=='*')
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}