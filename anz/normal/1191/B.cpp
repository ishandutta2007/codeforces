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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int main()
{
	string mj[3];
	cin >> mj[0] >> mj[1] >> mj[2];

	sort(mj, mj + 3);
	if (mj[0] == mj[1] && mj[1] == mj[2]) cout << 0;
	else if (mj[0][1] == mj[1][1] && mj[1][1] == mj[2][1] &&
		mj[0][0] + 1 == mj[1][0] && mj[1][0] + 1 == mj[2][0]) cout << 0;
	else
	{
		if (mj[0] == mj[1] ||
			mj[1] == mj[2] ||
			mj[2] == mj[0]) cout << 1;
		else if (mj[0][1] == mj[1][1] && abs(mj[0][0] - mj[1][0]) <= 2 ||
			mj[0][1] == mj[2][1] && abs(mj[0][0] - mj[2][0]) <= 2 ||
			mj[1][1] == mj[2][1] && abs(mj[1][0] - mj[2][0]) <= 2) cout << 1;
		else cout << 2;
	}
}