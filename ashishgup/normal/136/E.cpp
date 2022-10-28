#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int ct0, ct1, x;
string s;

bool c00()
{
	int max0=ct0 + x;
	return max0 > ct1;
}

bool c11()
{
	int max1=ct1 + x;
	return max1 > ct0 + 1;
}

bool c01()
{
	string str=s;
	int n0=n/2, n1=(n+1)/2;
	int reqz0=n0-ct0;
	int reqz1=n1-ct1;
	if(reqz0<0 || reqz1<0)
		return 0;
	for(auto &it:str)
	{
		if(it=='?')
		{
			if(reqz0)
			{
				reqz0--;
				it='0';
			}
			else
			{
				reqz1--;
				it='1';
			}
		}
	}
	return str.back()=='1';
}

bool c10()
{
	string str=s;
	int n0=n/2, n1=(n+1)/2;
	int reqz0=n0-ct0;
	int reqz1=n1-ct1;
	if(reqz0<0 || reqz1<0)
		return 0;
	for(auto &it:str)
	{
		if(it=='?')
		{
			if(reqz1)
			{
				reqz1--;
				it='1';
			}
			else
			{
				reqz0--;
				it='0';
			}
		}
	}
	return str.back()=='0';
}

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		ct0+=(s[i]=='0');
		ct1+=(s[i]=='1');
		x+=(s[i]=='?');
	}
	if(c00())
		cout<<"00"<<endl;
	if(c01())
		cout<<"01"<<endl;
	if(c10())
		cout<<"10"<<endl;
	if(c11())
		cout<<"11"<<endl;
	return 0;
}