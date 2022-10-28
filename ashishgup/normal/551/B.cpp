#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=256;

string a, b, c;
int f[N], f2[N], f3[N];

int32_t main()
{
	IOS;
	cin>>a>>b>>c;
	for(auto it:a)
		f[it]++;
	for(auto it:b)
		f2[it]++;
	for(auto it:c)
		f3[it]++;
	int ans=0, ct1=0, ct2=0;
	for(int i=0;;i++)
	{
		int check=1;
		for(char ch='a';ch<='z';ch++)
		{
			f[ch]-=i*f2[ch];
			if(f[ch]<0)
				check=0;
		}
		if(!check)
		{
			for(char ch='a';ch<='z';ch++)
			{
				f[ch]+=i*f2[ch];
			}
			break;
		}
		int j=INT_MAX;
		for(char ch='a';ch<='z';ch++)
		{	
			if(f3[ch]==0)
				continue;
			j=min(j, f[ch]/f3[ch]);
		}
		if(i+j>ans)
		{
			ans=i+j;
			ct1=i;
			ct2=j;
		}
		for(char ch='a';ch<='z';ch++)
		{
			f[ch]+=i*f2[ch];
		}
	}
	for(int i=1;i<=ct1;i++)
	{
		cout<<b;
	}
	for(int i=1;i<=ct2;i++)
	{
		cout<<c;
	}
	for(char ch='a';ch<='z';ch++)
	{
		f[ch]-=ct1*f2[ch];
		f[ch]-=ct2*f3[ch];
		for(int j=1;j<=f[ch];j++)
			cout<<ch;
	}
	return 0;
}