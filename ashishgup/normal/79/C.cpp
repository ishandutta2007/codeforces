#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
string s, pat;
int last[N];
set<pair<int, int> > index;
int lps[N];

void KMP()
{
	int i=0, j=0;
	while(i<n)
	{
		if(pat[j]==s[i])
		{
			j++;
			i++;
		}
		if(j==m)
		{
			index.insert({i-j, m});
			j=lps[j-1];
		}
		else if(i<n && pat[j]!=s[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
}

void computelps()
{
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
				len=lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	int temp;
	cin>>temp;
	for(int i=1;i<=temp;i++)
	{
		cin>>pat;
		m=pat.size();
		computelps();
		KMP();
	}
	for(int i=0;i<n;i++)
		last[i]=n;
	for(auto it:index)
	{
		last[it.first]=min(last[it.first], it.first + it.second - 2);
	}
	int ans1=0, ans2=0, curlast=n-1;
	for(int i=n-1;i>=0;i--)
	{
		curlast=min(curlast, last[i]);
		if(curlast>=i)
		{
			int len=curlast-i+1;
			if(len>ans1)
			{
				ans1=len;
				ans2=i;
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}