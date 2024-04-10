#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
 
using namespace std;
using ld = long double;
using pld = pair<ld, ld>;
#define x first
#define y second
 
const int MAXN = 100070, LOG = 17;
const ld EPS = 1e-15, INF = 1e5 + 1, PI = 3.14159265358979323846l;
int N, M;
pld pnts[MAXN];
ld polar[MAXN], len[MAXN];
int jump[LOG][MAXN];
 
void adjust(pld &i)
{
	while (i.x < 0) i.x += 2 * PI, i.y += 2 * PI;
	while (i.x >= 2 * PI) i.x -= 2 * PI, i.y -= 2 * PI;
}
 
void adjust(pld &i0, pld &i1)
{
	i0.y -= i0.x, i1.x -= i0.x, i1.y -= i0.x, i0.x = 0;
	adjust(i1);
}
 
bool contain(pld i0, pld i1)
{
	adjust(i0, i1);
	return i1.y - i0.y < EPS;
}
 
bool intersect(pld i0, pld i1)
{
	adjust(i0, i1);
	return i1.x - i0.y < EPS;
}

bool check(ld dist)
{
	vector<pld> intervals(N), removed;
	for (int i = 0; i < N; ++i) {
		ld angle = acos(dist / len[i]);
		// cout << dist << ' ' << len[i] << ": " << angle << endl;
		ld l = polar[i] - angle + EPS, r = polar[i] + angle + EPS;
		adjust(intervals[i] = pld(l, r));
	}
	sort(intervals.begin(), intervals.end());
	for (auto &i : intervals) {
		while (!removed.empty() && contain(removed.back(), i)) removed.pop_back();
		if (removed.empty() || !contain(i, removed.back())) removed.push_back(i);
	}
	while ((int) removed.size() > 1 && contain(removed.back(), removed.front())) removed.pop_back();
	// int start = 0;
	// for (; start < (int) removed.size() - 1 && contain(removed[start], removed.back()); ++start);
	// if (start > 0) removed.erase(removed.begin(), removed.begin() + start);
	// while ((int) removed.size() > 1 && contain(removed.back(), removed.front())) removed.pop_back();
 
	int sz = removed.size();
	// cout << dist << ": ";
	// for (auto &i : removed) cout << '(' << i.x << ", " << i.y << ") "; cout << endl;
	for (int i = 0; i < sz; ++i) removed.push_back(removed[i]);
 
	for (int i = 0, j = 0; i < sz; ++i) {
		for (j = max(i + 1, j); j < sz + i && intersect(removed[i], removed[j]); ++j);
		jump[0][i] = j - i;
		// cout << j % sz << ' ';
	}
	// cout << endl;
	for (int lg = 1; lg < LOG; ++lg) for (int i = 0; i < sz; ++i) {
		jump[lg][i] = jump[lg - 1][i] + jump[lg - 1][(i + jump[lg - 1][i]) % sz];
	}
 
	for (int i = 0; i < sz; ++i) {
		int total = 0;
		for (int lg = 0; lg < LOG; ++lg) if ((M >> lg) & 1) total += jump[lg][(total + i) % sz];
		if (total >= sz) return 1;
	}
 
	return 0;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> pnts[i].x >> pnts[i].y;
		polar[i] = atan2(pnts[i].y, pnts[i].x);
		len[i] = sqrt(pnts[i].x * pnts[i].x + pnts[i].y * pnts[i].y);
	}
 
	ld lo = 0, hi = *min_element(len, len + N);
	for (int trial = 0; trial < 50; ++trial) {
		ld mid = (lo + hi) / 2;
		if (check(mid)) lo = mid;
		else hi = mid;
	}
	cout << fixed << setprecision(9) << lo << endl;
}