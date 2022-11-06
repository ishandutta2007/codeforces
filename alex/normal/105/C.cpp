#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string pname = "c";

const int NMAX = 1010;
const string TYPE[3] = {"gladiator", "sentry", "physician"};
const string ZN[3] = {"weapon", "armor", "orb"};

int n, m;
string name[NMAX], zn[NMAX], hero[NMAX], type[NMAX], home[NMAX];
int param[NMAX][3], places[NMAX], bonus[NMAX], extra[NMAX];

void answer(int x, int y, int z)
{
	cout << name[x] << " " << places[x];
	forn(i, m)
		if (home[i] == name[x]) cout << " " << hero[i];
	cout << endl;

	cout << name[y] << " " << places[y];
	forn(i, m)
		if (home[i] == name[y]) cout << " " << hero[i];
	cout << endl;

	cout << name[z] << " " << places[z];
	forn(i, m)
		if (home[i] == name[z]) cout << " " << hero[i];
	cout << endl;

	exit(0);
}

int get(int now)
{
	int best = -1, ans = -1;
	forn(i, n)
		if (zn[i] == ZN[now] && best < param[i][now])
			best = param[i][now], ans = i;
	return ans;
}

vector <pii> q[3];
int ans[3];
int sum[NMAX];

void solve(int now)
{
	seta(sum, 0);
	sum[0] = 0;
	forn(i, q[now].size())
		sum[i + 1] = sum[i] - q[now][i].fs;

	int best = -1, ind = -1;
	forn(i, n)
		if (zn[i] == ZN[now])
		{
			int tmp = param[i][now] + sum[min((int) q[now].size(), places[i])];
			if (best < tmp)
			{
				best = tmp;
				ind = i;
			}
		}

	int cnt = min((int) q[now].size(), places[ind]);
	extra[ind] = places[ind] - cnt;
	places[ind] = cnt;
	forn(i, cnt)
		home[q[now][i].sc] = name[ind];
	ans[now] = ind;
}

int main()
{
	//freopen((pname + ".in").data(), "r", stdin);
	//freopen((pname + ".out").data(), "w", stdout);

	cin >> n;
	int sum = 0;
	forn(i, n)
	{
		cin >> name[i] >> zn[i];
		forn(j, 3)
			cin >> param[i][j];
		cin >> places[i];
		sum += places[i];
	}
	cin >> m;
	forn(i, m)
		cin >> hero[i] >> type[i] >> bonus[i] >> home[i];

	if (sum == m)
	{
		forn(i, m)
			forn(j, n)
				if (name[j] == home[i])
					forn(f, 3)
						if (TYPE[f] == type[i])
							param[j][f] += bonus[i];

		answer(get(0), get(1), get(2));
	}

	forn(i, m)
		forn(j, 3)
			if (type[i] == TYPE[j])
				q[j].pb(mp(-bonus[i], i));
	forn(j, 3)
		sort(all(q[j]));

	forn(i, m)
		home[i] = "";
	forn(j, 3)
		solve(j);
	forn(i, n)
		if (i != ans[0] && i != ans[1] && i != ans[2])
		{
			extra[i] = places[i];
			places[i] = 0;
		}

	int yl = 0;
	forn(i, m)
		if (home[i] == "")
		{
			while (extra[yl] == 0)
				yl++;
			home[i] = name[yl];
			extra[yl]--;
			places[yl]++;
		}
	answer(ans[0], ans[1], ans[2]);

	return 0;
}