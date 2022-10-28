#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k, ans=0;
string s;

bool checker(char a, char b)
{
	return (a==b  || a=='*' ||b=='*');
}

int32_t main()
{
	IOS;
	cin>>s>>k;
	n=s.size();
	for(int i=0;i<k;i++)
		s+='*';
	for(int len=n+k;len>=0;len--)
	{
		if(len%2)
			continue;
		for(int i=0;i+len-1<n+k;i++)
		{
			bool check=1;
			for(int j=0;j<len/2;j++)
				check&=checker(s[i+j], s[i+j+len/2]);
			if(check)
			{
				cout<<len;
				return 0;
			}
		}
	}
	return 0;
}