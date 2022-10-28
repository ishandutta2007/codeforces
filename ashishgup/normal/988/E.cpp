#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int ans=100;
string s;
string reqdd[4]={"00", "25", "50", "75"};

int get(int m)
{	
	int reqd=0, check=0;
	string str=s;
	int len=str.size();
	for(int j=1;j>=0;j--)
	{
		int k=len-1;
		if(j==0)
			k--;
		int storek=k;
		for(;k>=0;k--)
		{
			if(str[k]==reqdd[m][j])
			{
				for(int idx=k;idx<storek;idx++)
				{
					swap(str[idx], str[idx+1]);
					reqd++;
				}
				break;
			}
		}
		if(k==-1)
			return 100;
	}
	if(str[0]=='0')
	{
		int j;
		for(j=1;j<=len-3;j++)
		{
			if(str[j]!='0')
			{
				reqd+=j;
				break;
			}
		}
		if(j==len-2)
			return 100;
	}
	return reqd;
}

int32_t main()
{
	IOS;
	cin>>s;
	for(int i=0;i<4;i++)
	{
		ans=min(ans, get(i));
	}
	if(ans==100)
		ans=-1;
	cout<<ans;
	return 0;
}