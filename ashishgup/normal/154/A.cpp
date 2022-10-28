#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int k;
string s;
map<char, char> m;

int32_t main()
{
	IOS;
	cin>>s>>k;
	for(int i=1;i<=k;i++)
	{
		char ch1, ch2;
		cin>>ch1>>ch2;
		m[ch1]=ch2;
		m[ch2]=ch1;
	}
	int retain=0;
	for(int i=0;i<s.size();i++)
	{
		map<char, int> cnt;
		while(i<s.size()-1 && ((s[i+1]==s[i]) ||(s[i+1]==m[s[i]])))
		{
			cnt[s[i]]++;
			i++;
		}
		cnt[s[i]]++;
		int max1=0;
		for(auto it:cnt)
			max1=max(max1, it.second);
		retain+=max1;
	}
	cout<<s.size()-retain<<endl;
	return 0;
}