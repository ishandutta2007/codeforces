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
typedef long double ld;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

#define MAXN 112345

ll a[MAXN];
ll b[MAXN];
bool ans[MAXN];
ll cnt[MAXN];

int main()
{
	cin.sync_with_stdio(0);
 	cin.tie(0);
 	
 	int n;
 	cin >> n;
 	for (int i = 0; i < n; i++)
		cin >> a[i];
 	for (int i = 0; i < n; i++)
		cin >> b[i];
		
	ll val = 0;
 	for (int i = 0; i < n; i++)
 	{
		val += b[i];
		ans[i] = true;
		
		for (int j = 0; j < n; j++)
			if ((a[i] & (~a[j])) != 0)
				cnt[i]++;
	}

	int sz = n;
	
	while (true)
	{
		int better = -1;
		for (int i = 0; i < n; i ++)
			if (ans[i] == true && cnt[i] == sz - 1)
				better = i;

		if (better == -1)
			break;
		
		sz--;
		val -= b[better];
		
		for (int i = 0; i < n; i++)
			if ((a[i] & (~a[better])) != 0)
				cnt[i]--;
	}

	if (sz > 1)
		cout << val << endl;
	else
		cout << 0 << endl;	
}