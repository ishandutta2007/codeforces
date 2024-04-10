#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e4+5;
const int P1=31;
const int MOD1=1e9+7;

struct Hashs 
{
	vector<int> hashs;
	vector<int> pows;
	int P;
	int MOD;

	Hashs() {}

	Hashs(string &s, int P, int MOD) : P(P), MOD(MOD) 
	{
		int n = s.size();
		pows.resize(n+1, 0);
		hashs.resize(n+1, 0);
		pows[0] = 1;
		for(int i=n-1;i>=0;i--) 
		{
			hashs[i]=(1LL * hashs[i+1] * P + s[i] - 'a' + 1) % MOD;
			pows[n-i]=(1LL * pows[n-i-1] * P) % MOD;
		}
		pows[n] = (1LL * pows[n-1] * P)%MOD;
	}
	int get_hash(int l, int r) 
	{
		int ans=hashs[l] + MOD - (1LL*hashs[r+1]*pows[r-l+1])%MOD;
		ans%=MOD;
		return ans;
	}
};

int n, m;
bool cache[N], vis[N];
string s;
string a[N*10];
set<int> have;
map<int, string> store;
vector<int> lens;
Hashs str;

bool dp(int idx)
{
	if(idx==n)
		return 1;
	bool &ans=cache[idx];
	if(vis[idx])
		return cache[idx];
	vis[idx]=1;
	for(auto &it:lens)
	{
		if(idx+it-1>=n)
			continue;
		if(have.find(str.get_hash(idx, idx+it-1))!=have.end())
			cache[idx]|=dp(idx+it);
	}
	return cache[idx];
}

void path(int idx)
{
	if(idx==n)
		return;
	for(auto &it:lens)
	{
		if(idx+it-1>=n)
			continue;
		if(have.find(str.get_hash(idx, idx+it-1))!=have.end())
		{
			if(dp(idx+it))
			{
				string cur=store[str.get_hash(idx, idx+it-1)];
				reverse(cur.begin(), cur.end());
				cout<<cur<<" ";
				return path(idx+it);
			}
		}
	}
}

int32_t main()
{
	IOS;
	set<int> lengths;
	cin>>n>>s;
	str=Hashs(s, P1, MOD1);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		reverse(a[i].begin(), a[i].end());
		string temp=a[i];
		for(auto &it:temp)
			it=tolower(it);
		lengths.insert(a[i].size());
		int curhash=(Hashs(temp, P1, MOD1).get_hash(0, temp.size()-1));
		have.insert(curhash);
		store[curhash]=a[i];
	}	
	for(auto &it:lengths)
		lens.push_back(it);
	dp(0);
	path(0);
	return 0;
}