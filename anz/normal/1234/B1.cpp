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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
unordered_set <int> s;
deque <int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int t; cin >> t;
		if (s.find(t) != s.end()) continue;

		q.push_front(t);
		s.insert(t);
		if (q.size() > k)
		{
			int d = q.back(); q.pop_back();
			s.erase(d);
		}
	}

	cout << q.size() << "\n";
	for (auto i : q) cout << i << " ";
}