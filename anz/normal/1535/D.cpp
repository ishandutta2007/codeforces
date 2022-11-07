#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 300000;

int k, q;
int all;
string s;

int ans[N];
void update(int ptr, char c)
{
	if (ptr * 2 >= all)
	{
		if (c == '?') ans[ptr] = 2;
		else ans[ptr] = 1;
	}
	else
	{
		if (c == '0') ans[ptr] = ans[ptr * 2 + 1];
		else if (c == '1') ans[ptr] = ans[ptr * 2];
		else ans[ptr] = ans[ptr * 2] + ans[ptr * 2 + 1];
	}

	ptr /= 2;
	while (ptr)
	{
		char c = s[ptr - 1];
		if (c == '0') ans[ptr] = ans[ptr * 2 + 1];
		else if (c == '1') ans[ptr] = ans[ptr * 2];
		else ans[ptr] = ans[ptr * 2] + ans[ptr * 2 + 1];
		ptr /= 2;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> k >> s >> q;
	reverse(s.begin(), s.end());
	all = (1 << k) - 1;

	for (int i = 0; i < s.size(); i++)
	{
		int ptr = i + 1;
		update(ptr, s[i]);
	}

	while (q--)
	{
		int p; char c;
		cin >> p >> c;

		p = (all + 1 - p);
		s[p - 1] = c;
		update(p, c);

		cout << ans[1] << '\n';
	}
}