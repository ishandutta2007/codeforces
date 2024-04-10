#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, toth=0;
string s[N];

int ans(string &str)
{
	int sz=str.size();
	int h=0;
	int answer=0;
	for(int i=sz-1;i>=0;i--)
	{
		if(str[i]=='h')
			h++;
		else
			answer+=h;
	}
	return answer;
}

bool comp(string &a, string &b)
{
	string c=a+b;
	string d=b+a;
	return ans(c)>ans(d);
}	

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>s[i];
   	}
   	sort(s+1, s+n+1, comp);
   	string final="";
   	for(int i=1;i<=n;i++)
   	{
   		final+=s[i];
   	}
   	cout<<ans(final);
    return 0;
}