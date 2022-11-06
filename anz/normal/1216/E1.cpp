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

vector <ll> bd;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll curSum = 0;
	ll digitCnt = 1;
	ll numCnt = 9;
	bd.push_back(0);
	for (int i = 0; i < 9; i++)
	{
		ll tmp = 0;
		ll nine = 9;
		for (ll i = 1; i < digitCnt; i++)
		{
			tmp += i * nine * numCnt;
			nine *= 10;
		}

		tmp += digitCnt * (numCnt * (numCnt + 1)) / 2;

		curSum += tmp;
		bd.push_back(curSum);

		digitCnt++;
		numCnt *= 10;
	}

	int Q; cin >> Q;
	while (Q--)
	{
		ll k; cin >> k;
		auto it = lower_bound(bd.begin(), bd.end(), k);
		it--;
		ll idx = it - bd.begin();

		ll preSum = 0;
		ll nine = 9;
		for (ll i = 1; i <= idx; i++)
		{
			preSum += nine * i;
			nine *= 10;
		}

		ll curNum = 1;
		for (int i = 0; i < idx; i++) curNum *= 10;

		ll cnt = 1;
		ll curSum = *it;

		ll l = 0, r = nine;
		while (l < r)
		{
			ll mid = (l + r) / 2;

			ll val = mid * preSum + mid * (mid + 1) / 2 * (idx + 1);
			if (curSum + val < k)
				l = mid + 1;
			else
				r = mid;
		}

		r--;
		curSum += preSum * r + r * (r + 1) / 2 * (idx + 1);

		/*while (true)
		{
			ll plus = preSum + (idx + 1) * cnt;
			if (curSum + plus >= k) break;
			curSum += plus;
			cnt++;
			curNum++;
		}*/

		ll res_num = 1;
		ll last_cnt = 1;
		ll last_nine = 9;
		while (true)
		{
			ll plus = last_cnt * last_nine;
			if (curSum + plus >= k) break;
			curSum += plus;
			last_cnt++;
			last_nine *= 10;
			res_num *= 10;
		}

		ll div = (k - curSum) / last_cnt;
		if ((k - curSum) % last_cnt == 0) div--;
		res_num += div;
		curSum += div * last_cnt;

		int last_digit = k - curSum;
		vector <int> digit;
		while (res_num) digit.push_back(res_num % 10), res_num /= 10;
		reverse(digit.begin(), digit.end());
		cout << digit[last_digit - 1] << "\n";
	}
}