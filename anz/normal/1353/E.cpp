#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 1000001;
const int INF = 987654321;
int n, k;
string s;

int segTree[N * 4];
void update(int ptr, int l, int r, int i, int val)
{
	if (l > i || r < i) return;
	if (l == r)
	{
		segTree[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = min(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

int getVal(int ptr, int l, int r, int i, int j)
{
	if (l > j || r < i) return INF;
	if (i <= l && r <= j)return segTree[ptr];

	return min(
		getVal(ptr * 2, l, (l + r) / 2, i, j),
		getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j)
	);
}

int calc(vector <int>& v)
{
	for (int i = 0; i < v.size() * 4; i++) segTree[i] = INF;
	for (int i = 0; i < v.size(); i++)
	{
		int val = (i + 1) - v[i] + v.back() - v[i];
		// v[i] 0  + v[i+1] 1 
		update(1, 0, v.size() - 1, i, val);
	}

	int ans = INF;
	for (int i = 1; i < v.size(); i++)
	{
		int res = getVal(1, 0, v.size() - 1, i, v.size() - 1);

		res += v[i - 1] - (i - v[i - 1]);
		ans = min(ans, res);
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> s;

		int acnt[2] = { 0,0 };
		for (char c : s)
			acnt[c - '0']++;

		int ans = acnt[1];
		for (int i = 0; i < k; i++)
		{
			int cnt[2] = { 0,0 };

			vector <int> vec;
			vec.push_back(0);

			for (int j = i; j < s.size(); j += k)
			{
				int num = s[j] - '0';
				cnt[num]++;
				vec.push_back(num + vec.back());
				// 1   psum
			}

			int tmp = calc(vec);
			int res = acnt[1] - cnt[1] + tmp;

			ans = min(ans, res);
		}
		cout << ans << '\n';
	}
}