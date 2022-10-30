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
		x = 314159265; y = 358979323; z = 846264338; w = 327950288;
		double n = 1 / (double)(2 * 65536);
		for (int i = 0; i < 65536; i++) {
			nL[i] = log(((double)i / 65536) + n);
		}
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


	long long nextInt(long long min, long long max)
	{
		return min + nextInt(max - min + 1);
	}


	double nextDouble()
	{
		return (double)next() / ((long long)1 << 32);
	}


};
#define int long long
int MOD = 1000000007;
XorShift rnd;
bool ask(int l, int r) {
	cout << l << " " << r << endl;
	cout << flush;
	string res;
	cin >> res;
	return res == "Yes";
}
signed main() {
	int N, K; 
	cin >> N >> K;
	int mx = N;
	int mn = 1;
	int u = N;
	int d = 1;
	while (true) {
		if (u - d <= 4 * K + 1) {
			int m = d + rnd.nextInt((int)(u - d + 1));
			if (ask(m, m)) {
				return 0;
			}
		}
		else {
			int m = (u + d) / 2;
			if (ask(d, m)) {
				u = m;
			}
			else {
				d = m;
			}
		}
		u = min(u + K, N);
		d = max((int)1, d - K);
	}
	return 0;

}