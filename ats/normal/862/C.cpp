#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
//#define int long long
int MOD = 1000000007;
class XorShift {
public:
	unsigned int x, y, z, w;
	double nL[65536];

	XorShift()
	{
		init();
	}

	void init()
	{
		x = 314159267; y = 358979323; z = 846264338; w = 327950288;
		double n = 1 / (double)(2 * 65536);
		for (int i = 0; i < 65536; i++) {
			nL[i] = log(((double)i / 65536) + n);
		}
		next();
	}

	inline unsigned int next()
	{
		unsigned int t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
	}

	inline double nextLog() {
		return nL[next() & 0xFFFF];
	}

	int nextInt(int m)
	{
		return (int)(next() % m);
	}


	int nextInt(int min, int max)
	{
		return min + nextInt(max - min + 1);
	}


	double nextDouble()
	{
		return (double)next() / ((long long)1 << 32);
	}


};
const int64_t CYCLES_PER_SEC = 2500000000;
struct Timer {
	int64_t start;
	Timer() { reset(); }
	void reset() { start = getCycle(); }
	void plus(double a) { start -= (a * CYCLES_PER_SEC); }
	inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
	inline int64_t getCycle() {
		uint32_t low, high;
		__asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
		return ((int64_t)low) | ((int64_t)high << 32);
	}
};
XorShift rnd;
signed main() {
	Timer timer;
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, X;
	cin >> N >> X;
	set<int>st;
	int a;
	int s;
	while (timer.get()<1) {
		st.clear();
		s = 0;
		for (int i = 0; i < N - 1; i++) {
			a = rnd.nextInt(1000000);
			if (st.count(a) == 0) {
				st.insert(a);
				s = s^a;
			}
			else {
				i--;
			}
		}
		a = s^X;
		if (a >= 0 && a < 1000000) {
			if (st.count(a) == 0) {
				st.insert(a);
				break;
			}
		}
	}
	if (st.size() == N) {
		cout << "YES" << endl;
		bool f = true;
		for (auto w : st) {
			if (!f)cout << " ";
			f = false;
			cout << w;
		}
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}

}