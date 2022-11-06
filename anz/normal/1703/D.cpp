#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s[100001];
set <string> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		st.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			st.insert(s[i]);
		}
		for (int i = 0; i < n; i++)
		{
			bool flag = false;
			for (int j = 1; j < s[i].size(); j++)
			{
				string a = s[i].substr(0, j);
				string b = s[i].substr(j);

				if (st.find(a) != st.end() && st.find(b) != st.end()) flag = true;
			}

			if (flag) cout << 1;
			else cout << 0;
		}

		cout << '\n';
	}
}