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

int n;
vector<vector<ll>> box;
ll total = 0;
ll expected = 0;
vector<ll> bsum;
vector<ll> ssum;

vector<pii> poscycle[1 << 16];
bool tab[1 << 16];
bool pdbeen[1 << 16];


bool pd(int mask)
{
	if (mask == 0)
		return true;

	if (pdbeen[mask])
		return tab[mask];

	bool retv = false;
	for (int submask = mask; retv == false && submask > 0; submask = (mask & (submask - 1)))
		if (sz(poscycle[submask]) > 0 && pd(mask ^ submask))
			retv = true;

	pdbeen[mask] = true;
	return tab[mask] = retv;
}

pii ans[16];

void print_sol(int mask)
{
	if (mask == 0)
		return;
	for (int submask = mask; submask > 0; submask = (mask & (submask - 1)))
		if (sz(poscycle[submask]) > 0 && pd(mask ^ submask))
		{
			print_sol(mask ^ submask);
			for (int i = 0; i < sz(poscycle[submask]); i++)
				ans[poscycle[submask][i].first] = {box[poscycle[submask][i].first][poscycle[submask][i].second], poscycle[submask][(i-1+sz(poscycle[submask])) % sz(poscycle[submask])].first + 1};
			return;
		}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll x;
	box.assign(n, vector<ll>());
	bsum.assign(n, 0);
	map<ll, pair<int, int>> rdm;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x;

			total += x;
			box[i].push_back(x);
			bsum[i] += x;
			rdm[x] = {i, j};
		}
	}

	if (total % n != 0)
	{
		cout << "No" << endl;
		return 0;
	}

	expected = total / n;

	ssum.assign((1 << n), 0);
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				ssum[i] += expected - bsum[j];
	}

	map<pii, pii> prev;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < sz(box[i]); j++)
		{
			if (rdm.find(box[i][j] + expected - bsum[i]) != rdm.end())
				prev[pii(i,j)] = rdm[box[i][j] + expected - bsum[i]];
		}

	map<pii, int> been;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < sz(box[i]); j++)
			if (!been[pii(i, j)])
			{
				pii cur = {i, j};
				while (been[cur] == 0)
				{
					been[cur] = 1;
					if (prev.find(cur) != prev.end())
						cur = prev[cur];
				}

				if (been[cur] == 1 && prev.find(cur) != prev.end())
				{
					// found new cycle.
					vector<pii> cycle;
					do
					{
						cycle.push_back(cur);
						cur = prev[cur];
					} while (cur != cycle[0]);

					// debug(cycle);
					set<int> s;
					for (int k = 0; k < sz(cycle); k++)
						s.insert(cycle[k].first);
					if (sz(s) == sz(cycle))
					{
						int mask = 0;
						for (int k = 0; k < sz(cycle); k++)
							mask += (1 << cycle[k].first);
						poscycle[mask] = cycle;
					}
				}

				cur = {i, j};
				while (been[cur] != 2)
				{
					been[cur] = 2;
					if (prev.find(cur) != prev.end())
						cur = prev[cur];
				}
			}

	bool ok = pd((1 << n) - 1);

	if (ok)
	{
		cout << "Yes" << endl;
		print_sol((1 << n) - 1);
		for (int i = 0; i < n; i++)
			cout << ans[i].first << " " << ans[i].second << endl;
	}
	else
	{
		cout << "No" << endl;
	}	
}