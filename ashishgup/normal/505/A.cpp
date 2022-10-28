#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

bool check(string &s)
{
	int sz=s.size();
	for(int i=0, j=sz-1;i<j;i++, j--)
		if(s[i]!=s[j])
			return 0;
	return 1;
}

int n;
string s;

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	for(int i=0;i<=n;i++)
	{
		for(char ch='a';ch<='z';ch++)
		{
			string temp=s;
			string cur="";
			cur+=ch;
			temp.insert(i, cur);
			if(check(temp))
			{
				cout<<temp;
				return 0;
			}
		}
	}
	cout<<"NA";
	return 0;
}