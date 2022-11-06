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
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

const ll INF = 4294967295;
int l;
int cnt = 0;

ll f()
{
	ll ans = 0;
	while (cnt < l)
	{
		string od;
		cin >> od;
		cnt++;
		if (od == "add")
		{
			ans++;
			if (ans > INF)
			{
				cout << "OVERFLOW!!!";
				exit(0);
			}
		}
		else if (od == "for")
		{
			ll times;
			cin >> times;
			ll res = f();
			if (res*times > INF)
			{
				cout << "OVERFLOW!!!";
				exit(0);
			}
			res *= times;
			ans += res;
			if (ans > INF)
			{
				cout << "OVERFLOW!!!";
				exit(0);
			}
		}
		else
		{
			return ans;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> l;

	ll res = f();
	cout << res;
	//good
}