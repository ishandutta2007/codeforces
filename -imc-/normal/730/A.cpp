//MIPT Cryptozoology
//Room 202
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define itn int

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void precalc();

int TESTNUM = 0;
#define FILENAME ""

int main() {
	string s = FILENAME;
#ifdef YA
	//assert(!s.empty());
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
	cin.tie(0);
#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		++TESTNUM;
		solve();
	}
#ifdef YA
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

//#define int li


void solve() {
	int n;
	cin >> n;

	vector<int> r(n);
	for (int i = 0; i < n; i++)
		cin >> r[i];

	vector<pair<int, int>> inc(n);
	for (int i = 0; i < n; i++)
	{
		inc[i].first = -r[i];
		inc[i].second = i;
	}
	sort(inc.begin(), inc.end());

	for (int i = 0; i < n; i++)
		r[i] = -inc[i].first;

	for (int finalRating = 100; finalRating >= 0; finalRating--)
	{
		set<pair<int, int>> deltas;
		bool fail = false;
		int sumOther = 0;
		int nOther = 0;
		for (int i = 0; i < n; i++)
		{
			int d = r[i] - finalRating;

			if (d < 0)
			{
				fail = true;
				break;
			}

			if (d == 0) continue;

			if (i != 0)
			{
				sumOther += d;
				nOther++;
			}
			deltas.emplace(-d, i);
		}

		int dFirst = r[0] - finalRating;
#if 0
		cout << "first " << dFirst << ", sum " << sumOther << endl;
		if (fail) cout << "fail already" << endl;
#endif

		bool needPutMax = (dFirst + sumOther) % 2 == 1;
        
		if (needPutMax)
		{
			auto p1 = *deltas.begin();
			deltas.erase(deltas.begin());
			p1.first++;
			if (p1.first < 0) deltas.insert(p1);
			//dFirst--;
		}

		if (dFirst > sumOther)
			fail = true;

		//if (needPutMax && nOther <= 1) continue;

		//if (needPutMax && deltas.size() <= 2)
		//	fail = true;

		if (fail) continue;

		vector<pair<int, int>> matches;

		while (!deltas.empty())
		{
			//for (auto p : deltas) cout << p.first << " ";
			//cout << endl;

			auto p1 = *deltas.begin(); deltas.erase(deltas.begin());
			auto p2 = *deltas.begin(); deltas.erase(deltas.begin());

			p1.first++; p2.first++;

			matches.emplace_back(p1.second, p2.second);

			if (p1.first < 0) deltas.insert(p1);
			if (p2.first < 0) deltas.insert(p2);
		}

		cout << finalRating << "\n";
		cout << matches.size() << "\n";

		for (int i = 0; i < matches.size(); i++)
		{
			vector<int> play(n, 0);
			play[inc[matches[i].first].second] = play[inc[matches[i].second].second] = 1;

			if (needPutMax && matches[i].first && matches[i].second)
			{
				play[inc[0].second] = 1;
				needPutMax = false;
			}

			for (int i = 0; i < n; i++)
				cout << play[i];
			cout << "\n";
		}
		return;
	}

    // could not find normal solution

	cout << 0 << "\n";
	cout << (n - 1) * r[0] << "\n";

	for (int i = 0; i < r[0]; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				cout << (k == 0 || k == j) ? '1' : '0';
			cout << "\n";
		}
	}
}