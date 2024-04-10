#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
string s;

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

int32_t main()
{
	IOS;
	cin>>n>>k;
	cin>>s;
	vector<int> z=prefix_function(s);
	int inc=z[n-1];
	string ans=s;
	string add=s.substr(inc);
	for(int i=2;i<=k;i++)
		ans+=add;
	cout<<ans;
	return 0;
}