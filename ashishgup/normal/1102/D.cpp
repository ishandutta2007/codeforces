#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, reqd;
string s;
int f[5];

int32_t main()
{
	IOS;
	cin>>n>>s;
	reqd=n/3;
	for(auto &it:s)
		f[it-'0']++;
	for(int i=0;i<n;i++)
	{
		int cur=s[i]-'0';
		if(f[cur]>reqd)
		{
			for(int j=0;j<=cur-1;j++)
			{
				if(f[j]<reqd)
				{
					s[i]=(char)(j+'0');
					f[j]++;
					f[cur]--;
					break;
				}
			}
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		int cur=s[i]-'0';
		if(f[cur]>reqd)
		{
			for(int j=2;j>=0;j--)
			{
				if(j==cur)
					continue;
				if(f[j]<reqd)
				{
					s[i]=(char)(j+'0');
					f[j]++;
					f[cur]--;
					break;
				}
			}
		}
	}
	cout<<s;
	return 0;
}