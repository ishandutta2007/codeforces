#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 3e3 + 20;
const int mod[] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const int base[] = {727 , 4001};

string s[maxn] , t[maxn];

int l[maxn] , r[maxn] , pw[maxn][2] , hs[maxn][2] , ht[maxn][2];

void prepare()
{
	pw[0][0] = pw[0][1] = 1;

	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < 2; j++)
			pw[i][j] = 1LL * pw[i - 1][j] * base[j] % mod[j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	prepare();

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++)
		cin >> t[i];

	int st = -1;
	for(int i = 0; i < n; i++)
	{
		l[i] = 1e9 , r[i] = -1e9;
		for(int j = 0; j < (int)s[i].size(); j++)
			if(s[i][j] != t[i][j])
				l[i] = min(l[i] , j) , r[i] = max(r[i] , j);

		r[i]++;
		if(l[i] < r[i])
			st = i;
	}

	int sz = r[st] - l[st];

	for(int i = 0; i < n; i++)
		if(l[i] < r[i] && sz != r[i] - l[i])
		{
			return cout << "NO" << endl , 0;
		}

	while(r[st] < (int)s[st].size())
	{
		char A = s[st][r[st]] , B = t[st][r[st]];

		assert(A == B);

		bool f = 1;
		for(int i = 0; i < n; i++)
			if(l[i] < r[i])
				f &= (r[i] < (int)s[i].size() && A == s[i][r[i]]);

		if(!f)
			break;

		for(int i = 0; i < n; i++)
			if(l[i] < r[i])
				r[i]++;
		sz++;
	}

	while(l[st] > 0)
	{
		char A = s[st][l[st] - 1] , B = t[st][l[st] - 1];

		assert(A == B);

		bool f = 1;
		for(int i = 0; i < n; i++)
			if(l[i] < r[i])
				f &= (l[i] > 0 && A == s[i][l[i] - 1]);

		if(!f)
			break;

		for(int i = 0; i < n; i++)
			if(l[i] < r[i])
				l[i]--;
		sz++;
	}

	array<int , 2> Hs , Ht;
	Hs.fill(0) , Ht.fill(0);
	for(int i = l[st]; i < r[st]; i++)
		for(int j = 0; j < 2; j++)
		{
			Hs[j] = (1LL * Hs[j] * base[j] + s[st][i]) % mod[j];
			Ht[j] = (1LL * Ht[j] * base[j] + t[st][i]) % mod[j];
		}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < (int)s[i].size(); j++)
			for(int x = 0; x < 2; x++)
			{
				hs[j + 1][x] = (1LL * hs[j][x] * base[x] + s[i][j]) % mod[x];
				ht[j + 1][x] = (1LL * ht[j][x] * base[x] + t[i][j]) % mod[x];
			}

		bool f = (l[i] >= r[i]);
		for(int start = 0; start + sz <= (int)s[i].size(); start++)
		{
			array<int , 2> tmps , tmpt;

			for(int x = 0; x < 2; x++)
			{
				tmps[x] = (hs[start + sz][x] - (1LL * hs[start][x] * pw[sz][x] % mod[x]) + mod[x]) % mod[x];
				tmpt[x] = (ht[start + sz][x] - (1LL * ht[start][x] * pw[sz][x] % mod[x]) + mod[x]) % mod[x];
			}

			if(tmps == Hs)
			{
				if(l[i] != start || tmpt != Ht)
				{
					if(n == 10)
						cout << "SHIT" << endl;
					return cout << "NO" << endl , 0;
				}

				f = 1;
				break;
			}
		}

		if(!f)
		{
			if(n == 10)
				cout << "SHIT2" << endl;
			return cout << "NO" << endl , 0;
		}
	}

	cout << "YES" << endl;

	string ans1 , ans2;
	for(int i = l[st]; i < r[st]; i++)
		ans1 += s[st][i] , ans2 += t[st][i];

	cout << ans1 << endl << ans2 << endl;
}