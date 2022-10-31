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
int MOD = 1000000007;


const int64_t CYCLES_PER_SEC = 3500000000;

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
	void seeding(int a) {
		x = 314159265; y = 358979323; z = 846264338; w = ((long long)327950288 * (a + 1)) % 1000000007;
		for (int i = 0; i < (a % 1000); i++)next();
	}
	inline unsigned int next()
	{
		unsigned int t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
	}
	inline double nextLog() {
		return nL[next() & 0xFFFF];
	}
	inline int nextInt(int m)
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
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >>  M;
	vector<string> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int mask = (1 << N) - 1;
	vector<int> X(M, 0);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			X[i] *= 2;
			X[i] += A[j][i] - '0';
		}
	}

	int score = 0;
	for (int i = 0; i < M; i++) {
		int t = __builtin_popcount(X[i]);
		score += min(t, N - t);
	}

	Timer timer;
	XorShift rnd;
	int z = 0;
	int s = 0;
	int bestscore = score;
	while (timer.get() < 4) {


		int bit = (1 << rnd.nextInt(N));
		int tscore = 0;
		for (int i = 0; i < M; i++) {
			X[i] ^= bit;
			int t = __builtin_popcount(X[i]);
			tscore += min(t, N - t);
		}

		if (score >= tscore) {
			score = tscore;
			if (bestscore > score) {
				bestscore = score;
			}
		}
		else {
			for (int i = 0; i < M; i++) {
				X[i] ^= bit;
			}
			s++;
			if (s == 30) {
				int bit = 0;
				for (int i = 0; i < 5; i++) {
					bit ^= (1 << rnd.nextInt(N));
				}
				score = 0;
				for (int i = 0; i < M; i++) {
					X[i] ^= bit;
					int t = __builtin_popcount(X[i]);
					score += min(t, N - t);
				}
				s = 0;
			}
		}


	}
	
	cout << bestscore << endl;
}