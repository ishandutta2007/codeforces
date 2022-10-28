#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	int n=s.size();
	map<char, char> m;
	for(int i=1;i<=8;i++)
	{
		char ch1=(char)(i+'0');
		char ch2=(char)((9-i) + '0');
		m[ch1]=ch2;
	}
	int ans=1, curlen=1;
	for(int i=0;i<n;i++)
	{
		while(i+1<n && s[i]==m[s[i+1]])
		{
			i++;
			curlen++;
		}
		if(curlen>1 && curlen%2)
			ans*=(curlen+1)/2;
		curlen=1;
	}
	cout<<ans;
	return 0;
}