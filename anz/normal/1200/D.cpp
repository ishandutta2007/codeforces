#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, k;
char board[2001][2001];

int blackX[2001];
int blackY[2001];

int leftB[2001], rightB[2001];

int upB[2001], downB[2001];

int ans[2001][2001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(leftB, -1, sizeof leftB);
	memset(rightB, -1, sizeof rightB);
	memset(upB, -1, sizeof upB);
	memset(downB, -1, sizeof downB);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'B')
			{
				blackX[i]++, blackY[j]++;
				if (leftB[i] == -1)
					leftB[i] = j;
				rightB[i] = max(rightB[i], j);

				if (upB[j] == -1)
					upB[j] = i;
				downB[j] = max(downB[j], i);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) if (leftB[i] == -1) res++;
	for (int i = 0; i < n; i++) if (upB[i] == -1) res++;

	for (int j = 0; j <= n - k; j++)
	{
		deque <int> q;
		for (int i = 0; i < n; i++)
		{
			if (!q.empty() && q.front() <= i - k) q.pop_front();
			if (leftB[i] != -1 && leftB[i] >= j && rightB[i] < j + k)
				q.push_back(i);

			if (i >= k - 1)
			{
				ans[i - k + 1][j] += q.size();
			}
		}
	}

	for (int i = 0; i <= n - k; i++)
	{
		deque <int> q;
		for (int j = 0; j < n; j++)
		{
			if (!q.empty() && q.front() <= j - k) q.pop_front();
			if (upB[j] != -1 && upB[j] >= i && downB[j] < i + k)
				q.push_back(j);

			if (j >= k - 1)
			{
				ans[i][j - k + 1] += q.size();
			}
		}
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) tmp = max(tmp, ans[i][j]);
	cout << res + tmp;
}