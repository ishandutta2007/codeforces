#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e3 + 5;
 
string s, a, b;
int n, asz, bsz;
int cache[N][51][51];
bool vis[N][51][51];
int nxt[2][51][26];
int KMP[2][51];
 
void prefix_function(string &s, int c) 
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
	for(int i = 0; i < n; i++)
	{
		for(int ch = 0; ch < 26; ch++)
		{
			int idx = i;
			while(idx && (s[idx] - 'a') != ch)
				idx = pi[idx - 1];
			if(s[idx] - 'a' == ch)
				idx++;
			nxt[c][i][ch] = idx;
		}
		KMP[c][i] = pi[i];
	}
}
 
int dp(int i, int j, int k)
{
	if(i == n)
		return 0;
	int &ans = cache[i][j][k];
	if(vis[i][j][k])
		return ans;
	vis[i][j][k] = 1;
	int l = 0, r = 25;
	if(s[i] != '*')
		l = r = s[i] - 'a';
	ans = -1e9;
	for(int ch = l; ch <= r; ch++)
	{
		int nA = nxt[0][j][ch];
		int nB = nxt[1][k][ch];
		if(nA == asz && nB == bsz)
			ans = max(ans, dp(i + 1, KMP[0][asz - 1], KMP[1][bsz - 1]));
		else if(nA == asz)
			ans = max(ans, 1 + dp(i + 1, KMP[0][asz - 1], nB));
		else if(nB == bsz)
			ans = max(ans, -1 + dp(i + 1, nA, KMP[1][bsz - 1]));
		else
			ans = max(ans, dp(i + 1, nA, nB));
	}
	return ans;
}
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> s >> a >> b;
	prefix_function(a, 0);
	prefix_function(b, 1);
	n = s.size();
	asz = a.size();
	bsz = b.size();
	int ans = dp(0, 0, 0);
	cout << ans;
	return 0;
}