#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, t;
string ans="";
int same=0, diff=0;
string s1, s2;

char other(char ch1, char ch2)
{
	char ch='a';
	while(ch==ch1 || ch==ch2)
		ch++;
	return ch;
}

int32_t main()
{
	IOS;
	cin>>n>>t>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		same+=(s1[i]==s2[i]);
		diff+=(s1[i]!=s2[i]);
	}	
	if(t<(diff+1)/2)
	{
		cout<<"-1";
		return 0;
	}
	int x=min(n-t, same);
	int y=max(n-t-same, 0LL);
	int z=max(n-t-same, 0LL);
	for(int i=0;i<n;i++)
	{
		if(s1[i]==s2[i])
		{
			if(x>0)
				ans+=s1[i], x--;
			else
				ans+=other(s1[i], s2[i]);
		}
		else
		{
			if(y>0)
				ans+=s1[i], y--;
			else if(z>0)
				ans+=s2[i], z--;
			else
				ans+=other(s1[i], s2[i]);
		}
	}
	cout<<ans;
	return 0;
}