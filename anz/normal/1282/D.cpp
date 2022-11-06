#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);

	int aCnt, bCnt;

	for (int i = 0; i < 300; i++) cout << "a";
	cout << endl;

	cin >> aCnt;
	if (aCnt == 0) return 0;
	aCnt = 300 - aCnt;

	for (int i = 0; i < 300; i++) cout << "b";
	cout << endl;

	cin >> bCnt;
	if (bCnt == 0) return 0;
	bCnt = 300 - bCnt;

	int s = aCnt + bCnt;
	int res = -1;

	string pre, suf;
	while (true)
	{
		if (aCnt == 0)
		{
			cout << pre;
			for (int i = 0; i < bCnt; i++) cout << "b";
			cout << endl;
			cin >> res;
			return 0;
		}
		else if (bCnt == 0)
		{
			cout << pre;
			for (int i = 0; i < aCnt; i++) cout << "a";
			cout << endl;
			cin >> res;
			return 0;
		}

		cout << pre;
		cout << "b";
		for (int i = 0; i < s - pre.size() - 1; i++) cout << "a";
		cout << endl;

		cin >> res;
		if (res == 0) return 0;
		if (res == -1) return 1;

		res = s - pre.size() - res;
		if (res >= aCnt + 1)
		{
			pre += "b";
			bCnt--;
		}
		else
		{
			pre += "a";
			aCnt--;
		}
	}
}