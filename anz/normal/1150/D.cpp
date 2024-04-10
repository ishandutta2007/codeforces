#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <unordered_map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	while (b)
	{
		for (; b; a %= b, swap(a, b));
		return a;
	}
	return a;
}

int n, q;
string universe;

string re[4];

int nextDir[100001][26];
int dp[251][251][251];
// religion 1 2 3     prefix  

void update(int num)
{
	for (int i = (num == 1 ? re[1].size() : 0); i <= re[1].size(); i++)
		for (int j = (num == 2 ? re[2].size() : 0); j <= re[2].size(); j++)
			for (int k = (num == 3 ? re[3].size() : 0); k <= re[3].size(); k++)
			{
				dp[i][j][k] = 987654321;
				if (i && dp[i - 1][j][k] != 987654321)
					dp[i][j][k] = min(dp[i][j][k], nextDir[dp[i - 1][j][k]][re[1][i - 1] - 'a']);
				if (j && dp[i][j - 1][k] != 987654321)
					dp[i][j][k] = min(dp[i][j][k], nextDir[dp[i][j - 1][k]][re[2][j - 1] - 'a']);
				if (k && dp[i][j][k - 1] != 987654321)
					dp[i][j][k] = min(dp[i][j][k], nextDir[dp[i][j][k - 1]][re[3][k - 1] - 'a']);
			}
}

int main()
{
	cin >> n >> q;
	cin >> universe;

	for (int i = 0; i < 26; i++) nextDir[n][i] = 987654321;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < 26; j++)
		{
			if (universe[i] - 'a' == j) nextDir[i][j] = i + 1;
			else nextDir[i][j] = nextDir[i + 1][j];
		}
	}

	while (q--)
	{
		char op, letter;
		int num;
		cin >> op >> num;
		if (op == '+')
		{
			cin >> letter;
			re[num].push_back(letter);
			update(num);
		}
		else
		{
			re[num].pop_back();
		}

		if (dp[re[1].size()][re[2].size()][re[3].size()] != 987654321)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}