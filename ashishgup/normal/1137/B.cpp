#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5e5 + 5;

vector<int> prefix_function(string &s) 
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int n, m;
string s, t;
int suf0[N], suf1[N];
int f[5];

void work()
{
	vector<int> lps = prefix_function(t);
	int idx = 0;
	string ans = "";
	while(f[0] >= suf0[idx] && f[1] >= suf1[idx])
	{
		for(int j=idx;j<m;j++)
		{
			ans += t[j];
			f[t[j] - '0']--;
		}	
		idx = lps[m-1];
	}
	while(f[0] > 0)
	{
		ans += '0';
		f[0]--;
	}
	while(f[1] > 0)
	{
		ans += '1';
		f[1]--;
	}
	cout<<ans;
}

int32_t main()
{
	IOS;
	cin>>s>>t;
	n = s.size();
	m = t.size();
	for(auto &it:s)
		f[it-'0']++;
	for(int i=m-1;i>=0;i--)
	{
		suf0[i] = suf0[i+1];
		suf1[i] = suf1[i+1];
		if(t[i]=='0')
			suf0[i]++;
		else
			suf1[i]++;
	}
	work();
	return 0;
}