//Solved without appending

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

string a, b;
int f[10];

int ctdig(int k)
{
	int ans=0;
	while(k>0)
	{
		ans++;
		k/=10;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>a>>b;
	for(auto it:a)
		f[it-'0']++;
	for(auto it:b)
		f[it-'0']--;
	string endmost="";
	for(int len=1;len<=6;len++)
	{
		int remlen=a.size()-len;
		if(ctdig(remlen)==len)
		{
			while(remlen>0)
			{
				int dig=remlen%10;
				f[dig]--;
				endmost+=(char)(dig+'0');
				remlen/=10;
			}
			break;
		}		
	}
	string ans2="";
	for(int i=0;i<=9;i++)
	{
		for(int j=1;j<=f[i];j++)
			ans2+=(char)(i+'0');
	}
	reverse(endmost.begin(), endmost.end());
	string mid=b;
	string left="", right="";
	if(f[0]>0||b[0]=='0')
	{	
		for(int i=1;i<=9;i++)
		{
			if(f[i]>=1)
			{
				f[i]--;
				left+=(char)(i+'0');
				break;
			}
		}
	}
	if(left.size())
	{
		for(int j=1;j<=f[0];j++)
		{
			left+='0';
		}
		f[0]=0;
	}
	for(int i=1;i<mid[0]-'0';i++)
	{
		for(int j=1;j<=f[i];j++)
		{
			left+=(char)(i+'0');
		}
		f[i]=0;
	}
	string s1=b[0]+mid;
	string s2=mid+b[0];
	if(s1<s2)
	{
		for(int j=1;j<=f[b[0]-'0'];j++)
		{
			left+=b[0];
		}
	}
	else
	{
		for(int j=1;j<=f[b[0]-'0'];j++)
		{
			right+=b[0];
		}
	}
	if(f[0]>0)
	{
		for(int j=1;j<=f[0];j++)
		{
			right+='0';
		}
	}
	for(int i=mid[0]-'0'+1;i<=9;i++)
	{
		for(int j=1;j<=f[i];j++)
		{
			right+=(char)(i+'0');
		}
	}
	string ans1=left+mid+right;
	ans2=b+ans2;
	if(b[0]!='0')
		ans1=min(ans1, ans2);
	cout<<ans1;
	return 0;
}