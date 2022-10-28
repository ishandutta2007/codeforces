#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=205;
const int MOD=1e9+7;

int n, l=0, r=0, sz=0;
string s;
int cache[N][N][N], cache2[N][2];
vector<int> lps;

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

int getidx(int i, char ch)
{
	if(i==0)
		return 0;
	int idx=(ch==')');
	int &ans=cache2[i][idx];
	if(ans!=-1)
		return ans;
	if(s[i]==ch)
		ans=i;
	else
		ans=getidx(lps[i-1], ch);
	return ans;
}

int dp(int idx, int bal, int i)
{
	if(bal<0||idx>n)
		return 0;
	if(idx==n)
		return (bal==0 && i==sz);
	int &ans=cache[idx][bal][i];
	if(ans!=-1)
		return ans;
	ans=0;
	if(i<sz && s[i]=='(')
	{
		ans+=dp(idx+1, bal+1, i+1);
		int cur=getidx(i, ')');
		if(s[cur]==')')
			cur++;
		ans+=dp(idx+1, bal-1, cur);
	}
	else if(i<sz && s[i]==')')
	{
		int cur=getidx(i, '(');
		if(s[cur]=='(')
			cur++;
		ans+=dp(idx+1, bal+1, cur);
		ans+=dp(idx+1, bal-1, i+1);
	}
	else
	{
		ans+=dp(idx+1, bal+1, i);
		ans+=dp(idx+1, bal-1, i);
	}
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin>>n>>s;
	n*=2;
	sz=s.size();
	lps=prefix_function(s);
	int ans=dp(0, 0, 0);
	cout<<ans;
	return 0;
}