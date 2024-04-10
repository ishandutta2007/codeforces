#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

bool check(string &s)
{
	int dig=0, up=0, low=0;
	for(auto &it:s)
	{
		dig|=isdigit(it);
		up|=isupper(it);
		low|=islower(it);
	}
	return (dig&&up&&low);
}

vector<char> v={'A', 'a', '0'};

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		map<char, int> m;
		int n=s.size();
		if(check(s))
		{
			cout<<s<<endl;
			continue;
		}
		bool printed=0;
		for(int i=0;i<n;i++)
		{
			for(auto j:v)
			{
				char ch=s[i];
				s[i]=j;
				if(check(s))
				{
					cout<<s<<endl;
					printed=1;
					break;
				}
				s[i]=ch;
			}
			if(printed)
				break;
		}
		if(printed)
			continue;
		for(int i=0;i<n-1;i++)
		{
			for(auto j:v)
			{
				for(auto k:v)
				{
					char ch=s[i], ch2=s[i+1];
					s[i]=j;
					s[i+1]=k;
					if(check(s))
					{
						cout<<s<<endl;
						printed=1;
						break;
					}
					s[i]=ch;
					s[i+1]=ch2;
				}
				if(printed)
					break;
			}
			if(printed)
				break;
		}
	}
	return 0;
}