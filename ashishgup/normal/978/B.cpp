#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, ans=0;
string s;

int32_t main()
{
	IOS;
	cin>>n>>s;
	char ch='?';
	int len=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]==ch)
		{
			if(ch=='x')
			{
				if(len==2)
				{
					ans++;
				}
				else
					len++;
			}
			else
			{
				len++;
			}
		}
		else
		{
			ch=s[i];
			len=1;
		}
	}
	cout<<ans;
	return 0;
}