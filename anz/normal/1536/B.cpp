#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;
set <string> st;

bool hasAns;
void solve(string s, int rm)
{
	if (rm == 0)
	{
		if (st.find(s) == st.end())
		{
			cout << s << '\n';
			hasAns = true;
		}
		return;
	}

	for (int i = 0; i < 26 && !hasAns; i++)
	{
		string ns = s + char('a' + i);
		solve(ns, rm - 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		st.clear();
		hasAns = false;
		cin >> n >> s;
		for (int i = 0; i < n; i++)
		{
			st.insert(s.substr(i, 1));
			st.insert(s.substr(i, 2));
			st.insert(s.substr(i, 3));
			st.insert(s.substr(i, 4));
			st.insert(s.substr(i, 5));
		}

		string s;
		solve(s, 1);
		if (!hasAns) solve(s, 2);
		if (!hasAns) solve(s, 3);
		if (!hasAns) solve(s, 4);
		if (!hasAns) solve(s, 5);
	}
}