#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, p;
string s;
set<char> have;

void work(int i)
{
	if(i<0)
	{
		cout<<"NO";
		exit(0);
	}	
	for(int k=max(0LL, i-2);k<=i-1;k++)
	{
		have.erase(s[k]);
	}
	auto it=have.upper_bound(s[i]);
	for(int k=max(0LL, i-2);k<=i-1;k++)
	{
		have.insert(s[k]);
	}
	if(it==have.end())
	{
		return work(i-1);
	}	
	char ch=*it;
	s[i]=ch;
	for(int j=i+1;j<n;j++)
	{
		for(int k=max(0LL, j-2);k<=j-1;k++)
		{
			have.erase(s[k]);
		}
		auto it=have.begin();
		char ch=*it;
		for(int k=max(0LL, j-2);k<=j-1;k++)
		{
			have.insert(s[k]);
		}
		s[j]=ch;
	}
}

int32_t main()
{
	IOS;
	cin>>n>>p;
	cin>>s;
	for(int i=1;i<=p;i++)
	{
		have.insert((char)(i+'a'-1));
	}
	work(n-1);
	cout<<s;
	return 0;
}