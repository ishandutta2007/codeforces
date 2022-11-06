#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <complex>
#include <bitset>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define re return
#define fi first
#define se second

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const long double eps = 1e-9;
const int inf = (int)1e9 + 100;//(1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x; }

const long long mod = (long long) 1e9 + 7;

#define filename "b"

int n, ans, d[5010][5010], c[5010], m;

int main (){
	//freopen(filename".in", "r", stdin);
	//freopen(filename".out", "w", stdout);

	cin >> n >> m;
	forn(i, n)
	{
		double tmp;
		cin >> c[i] >> tmp;
		c[i]--;
	}

	forn(i, n + 1)
		forn(j, m)
			d[i][j] = n;
	d[0][0] = 0;
	forn(i, n)
		forn(j, m)
		{
			if (c[i] == j) d[i + 1][j] = min(d[i + 1][j], d[i][j]);
			else d[i + 1][j] = min(d[i + 1][j], d[i][j] + 1);
			d[i][j + 1] = min(d[i][j + 1], d[i][j]);
		}

	ans = n;
	forn(i, m)
		ans = min(ans, d[n][i]);
	cout << ans << endl;

	return 0;
}