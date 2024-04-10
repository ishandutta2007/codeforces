#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

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

vector<int> find_occurences(string &text, string &pattern)
{
	string cur=pattern + '#' + text;
	int sz1=text.size(), sz2=pattern.size();
	vector<int> v;
	vector<int> lps=prefix_function(cur);
	for(int i=sz2+1;i<=sz1+sz2;i++)
	{
		if(lps[i]==sz2)
			v.push_back(i-2*sz2);
	}
	return v;
}

int32_t main()
{
	IOS;
	int ans=0;
	string s;
	cin>>s;
	string a="heavy";
	string b="metal";
	vector<int> p, q;
	p=find_occurences(s, a);
	q=find_occurences(s, b);
	for(auto &it:p)
	{	
		auto cnt=q.end() - lower_bound(q.begin(), q.end(), it);
		ans+=cnt;
	} 
	cout<<ans;
	return 0;
}