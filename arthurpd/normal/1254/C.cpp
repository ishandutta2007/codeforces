#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }

template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}

#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

int side(int i, int j, int k)
{
	printf("%d %d %d %d\n", 2, i, j, k);
	fflush(stdout);
	int retv;
	scanf("%d", &retv);
	return retv;
}

ll area(int i, int j, int k)
{
	printf("%d %d %d %d\n", 1, i, j, k);
	fflush(stdout);
	ll retv;
	scanf("%lld", &retv);
	return retv;
}

int main()
{
	int n;
	scanf("%d", &n);
	int p1 = 1, p2 = 2;
	for (int i = 3; i <= n; i++)
		if (side(p1, p2, i) == -1)
			p2 = i;
	
	map<int, ll> rdm;
	int mid = 0;
	for (int i = 2; i <= n; i++)
	{
		if (i != p2)
		{
			rdm[i] = area(p1, p2, i);
			if (mid == 0 || rdm[i] > rdm[mid])
				mid = i;
		}
	}

	vector<int> pre_mid;
	vector<int> pos_mid;
	for (int i = 2; i <= n; i++)
	{
		if (i != p2 && i != mid)
		{
			if (side(p1, mid, i) == 1)
				pos_mid.push_back(i);
			else
				pre_mid.push_back(i);			
		}
	}

	sort(pre_mid.begin(), pre_mid.end(), [&rdm](int i, int j) { return rdm[i] < rdm[j]; });
	sort(pos_mid.begin(), pos_mid.end(), [&rdm](int i, int j) { return rdm[i] > rdm[j]; });

	printf("0");
	printf(" %d %d", p1, p2);
	for (int i = 0; i < sz(pre_mid); i++)
		printf(" %d", pre_mid[i]);
	printf(" %d", mid);
	for (int i = 0; i < sz(pos_mid); i++)
		printf(" %d", pos_mid[i]);
	printf("\n");
	fflush(stdout);
}