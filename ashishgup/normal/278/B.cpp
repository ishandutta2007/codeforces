#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
set<string> store;
string a[N];

void generate(string &s)
{
	int sz=s.size();
	for(int i=0;i<sz;i++)
	{
		string cur="";
		for(int j=i;j<sz;j++)
		{
			cur+=s[j];
			store.insert(cur);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		generate(a[i]);	
	}
	queue<string> q;
	for(char ch='a';ch<='z';ch++)
	{
		string cur="";
		cur+=ch;
		q.push(cur);
	}
	while(true)
	{
		string cur=q.front();
		q.pop();
		if(store.find(cur)==store.end())
		{
			cout<<cur;
			return 0;
		}
		for(char ch='a';ch<='z';ch++)
		{
			q.push(cur+ch);
		}
	}
	return 0;
}