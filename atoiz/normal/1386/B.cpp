/*input
1 1 1
3
A 0 0 1
A 1 0 0
A 0 1 0

1 2 3
6
A 5 6 7
A 3 10 17
R 1
A 15 18 21
A 5 10 15
R 3

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <array>
#include <fstream>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;
const double EPS = 1e-6;
struct Bottle : array<ll, 3>
{
	friend istream& operator>> (istream &in, Bottle &b)
	{
		return in >> b[0] >> b[1] >> b[2];
	}

	friend int ccw (const Bottle &b0, const Bottle &b1)
	{
		double det = (double) b0[0] * b1[1] - (double) b1[0] * b0[1];
		if (det > EPS) return +1;
		if (det < -EPS) return -1;
		return 0;
	}

	friend bool operator< (const Bottle &b0, const Bottle &b1)
	{
		bool f0 = (b0[1] < 0 || (b0[1] == 0 && b0[0] < 0));
		bool f1 = (b1[1] < 0 || (b1[1] == 0 && b1[0] < 0));
		if (f0 != f1) return f0 < f1;
		return ccw(b0, b1) > 0;
	}

	Bottle opp() const
	{
		Bottle b = *this;
		b[0] = -b[0], b[1] = -b[1];
		return b;
	}
};

const int MAXN = 100003;
int N, X, C = 0;
Bottle pivot, bottles[MAXN];
map<Bottle, int> cntMap;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> pivot >> N;
	for (X = 2; pivot[X] == 0; --X);
	swap(pivot[2], pivot[X]);
	assert(pivot[2] > 0);
	
	ll cntOpp = 0;
	int cnt0 = 0, cntGap = 0;
	while (N--) {
		string op;
		cin >> op;
		if (op == "A") {
			Bottle &cur = bottles[++C];
			cin >> cur;
			swap(cur[2], cur[X]);
			if (cur[2] == 0) cur[0] += pivot[0], cur[1] += pivot[1], cur[2] += pivot[2];
			cur[0] = cur[0] * pivot[2] - pivot[0] * cur[2];
			cur[1] = cur[1] * pivot[2] - pivot[1] * cur[2];
			ll d = abs(__gcd(__gcd(cur[0], cur[1]), cur[2]));
			cur[0] /= d, cur[1] /= d, cur[2] /= d;
			// cout << cur[0] << ' ' << cur[1] << ' ' << cur[2] << endl;

			if (cur[0] == 0 && cur[1] == 0) ++cnt0;
			else {
				Bottle opp = cur.opp();
				if (cntMap.find(opp) != cntMap.end()) cntOpp += cntMap[opp];
				++cntMap[cur];

				if ((int) cntMap.size() > 1 && cntMap[cur] == 1) {
					auto it = cntMap.find(cur);
					auto lef = prev(it == cntMap.begin() ? cntMap.end() : it)->first;
					auto rig = (next(it) == cntMap.end() ? cntMap.begin() : next(it))->first;
					if (ccw(lef, cur) < 0) ++cntGap;
					if (ccw(cur, rig) < 0) ++cntGap;
					if (lef != rig && ccw(lef, rig) < 0) --cntGap;
				}
			}
		} else {
			int id;
			cin >> id;
			Bottle cur = bottles[id];
			if (cur[0] == 0 && cur[1] == 0) --cnt0;
			else {
				Bottle opp = cur.opp();
				if (cntMap.find(opp) != cntMap.end()) cntOpp -= cntMap[opp];
				--cntMap[cur];

				if (cntMap[cur] == 0) {
					auto it = cntMap.find(cur);
					if ((int) cntMap.size() > 1) {
						auto lef = prev(it == cntMap.begin() ? cntMap.end() : it)->first;
						auto rig = (next(it) == cntMap.end() ? cntMap.begin() : next(it))->first;
						if (ccw(lef, cur) < 0) --cntGap;
						if (ccw(cur, rig) < 0) --cntGap;
						if (lef != rig && ccw(lef, rig) < 0) ++cntGap;
					}
					cntMap.erase(it);
				}
			}
		}

		int ans = 0;
		if (cnt0) ans = 1;
		else if (cntOpp) ans = 2;
		else if ((int) cntMap.size() > 1 && cntGap == 0) ans = 3;
		cout << ans << '\n';
	}
}