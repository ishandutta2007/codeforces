#include <bits/stdc++.h>
using namespace std;
#define int long long
class XorShift {
public:
	unsigned int x, y, z, w;


	XorShift()
	{
		init();
	}

	void init()
	{
		x = 314159265; y = 358979323; z = 846264338; w = 327950288;
	}

	unsigned int next()
	{
		unsigned int t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
	}

	long long nextLong(long long m)
	{
		return (long)((((unsigned long long)next() << 32) + next()) % (unsigned long long)m);
	}

	int nextInt(int m)
	{
		return (int)(next() % m);
	}

	int nextIntP(int a)
	{
		return (int)pow(a, nextDouble());
	}

	int nextInt(int min, int max)
	{
		return min + nextInt(max - min + 1);
	}


	double nextDouble()
	{
		return (double)next() / ((long long)1 << 32);
	}

	double nextDoubleP(double a)
	{
		return pow(a, nextDouble());
	}
};
XorShift rnd;
int res = -1;
int st = 0;
int kv = -1;
bool f;
vector<int> used;
int n, start, x;
int query(int a) {
	int v, ne;
	cout <<  "? " << a << endl;
	cout.flush();
	cin >> v >> ne;
		ne--;
	if (ne >= 0) {
		used[ne] = 1;
	}
	if (v <= x) {
		if (kv < v) {
			kv = v;
			st = ne;
		}
	}
	if (v >= x) {
		f = true;
		res = min(res, v);
		if (res == -1) {
			res = v;
		}
	}
	return ne;
}
signed main() {
	
	cin >> n >> start >> x;
	st = start - 1;
	vector<int> pm(n);
	used.resize(n, 0);
	for (int i = 0; i < n; i++) {
		pm[i] = i;
	}
	for (int i = n - 1; i >= 1; i--) {
		int a = rnd.nextInt(i + 1);
		swap(pm[i], pm[a]);
	}
	
	query(start);
	int c = 0;
	int ind = 0;
	while (c<1000 && ind<n) {
		if (used[pm[ind]] == 0) {
			query(pm[ind] + 1);
			c++;
		}
		ind++;
	}
	ind = st;
	int k;
	f = false;
	while (!f && ind >= 0) {
		ind = query(ind + 1);
	}
	cout << "! " << res << endl;
	cout.flush();
	return 0;
}