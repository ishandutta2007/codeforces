#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

bool isVowel(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	string s, t;
	cin>>s>>t;
	if(s.size()!=t.size())
	{
		cout<<"No";
		return 0;
	}
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]==t[i])
			continue;
		int x=isVowel(s[i]), y=isVowel(t[i]);
		if(x!=y)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}