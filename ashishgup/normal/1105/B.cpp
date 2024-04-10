#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, x=0;
string s;

int32_t main()
{
	IOS;
	cin>>n>>k>>s;
	for(char ch='a';ch<='z';ch++)
	{
		int curx=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=ch)
				continue;
			int j=i, len=1;
			while(j+1<n && s[j+1]==ch && len<k)
			{
				len++;
				j++;
			}	
			if(len==k)
				curx++;
			i=j;
		}
		x=max(x, curx);
	}
	cout<<x;
	return 0;
}