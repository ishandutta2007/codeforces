#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n;
map<string, int> m;
string s[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int len=9;
		for(int j=0;j<len;j++)
		{
			string str="";
			for(int k=j;k<len;k++)
			{
				str+=s[i][k];
				if(m.find(str)==m.end())
					m[str]=i;
				else if(m[str]!=i)
					m[str]=-1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int len=9;
		int mxlen=10; string ans;
		for(int j=0;j<len;j++)
		{
			string str="";
			for(int k=j;k<len;k++)
			{
				str+=s[i][k];
				if(m[str]!=-1)
				{
					if(k-j+1<mxlen)
					{
						mxlen=k-j+1;
						ans=str;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}