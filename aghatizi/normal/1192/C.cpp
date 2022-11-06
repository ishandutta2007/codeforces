#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 65;
const int mod = 998244353;

set<string> ver[20];

int dp[maxn][maxn][maxn] , pd[maxn][maxn] , st[maxn][maxn][maxn][maxn] , cnt[maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
}

int fac(int x)
{
	if(x == 4)
		return 24;
	if(x == 3)
		return 6;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<char , int> mp;
	int id = 0;
	for(char i = 'a'; i <= 'z'; i++)
		mp[i] = id++;
	for(char i = 'A'; i <= 'Z'; i++)
		mp[i] = id++;
	for(char i = '0'; i <= '9'; i++)
		mp[i] = id++;

	for(int i = 0; i < id; i++)
		for(int j = i; j < id; j++)
			for(int k = j; k < id; k++)
				for(int l = k; l < id; l++)
				{
					cnt[i]++ , cnt[j]++ , cnt[k]++ , cnt[l]++;
					st[i][j][k][l] = 24 / fac(cnt[i]) , cnt[i] = 0;
					if(j > i)
						st[i][j][k][l] /= fac(cnt[j]) , cnt[j] = 0;
					if(k > j)
						st[i][j][k][l] /= fac(cnt[k]) , cnt[k] = 0;
					if(l > k)
						st[i][j][k][l] /= fac(cnt[l]) , cnt[l] = 0;
				}

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for(auto &ch : s)
			ch = mp[ch];

		ver[s.size()].insert(s);
		reverse(s.begin() , s.end());
		ver[s.size()].insert(s);
	}

	int res = 0;
	for(int sz = 3; sz <= 10; sz++)
	{
		memset(dp , 0 , sizeof dp);
		memset(pd , 0 , sizeof pd);

		for(auto x : ver[sz])
			pd[x[0]][x.back()]++;

		for(int i = 0; i < id; i++)
			for(int j = i; j < id; j++)
				for(int k = j; k < id; k++)
					for(int l = 0; l < id; l++)
						mkay(dp[i][j][k] += 1LL * pd[i][l] * pd[j][l] % mod * pd[k][l] % mod);

		for(int i = 0; i < id; i++)
			for(int j = i; j < id; j++)
				for(int k = j; k < id; k++)
					for(int l = k; l < id; l++)
						mkay(res += 1LL * st[i][j][k][l] * dp[i][j][k] % mod * dp[i][j][l] % mod * dp[i][k][l] % mod * dp[j][k][l] % mod);
	}

	cout << res << endl;
}