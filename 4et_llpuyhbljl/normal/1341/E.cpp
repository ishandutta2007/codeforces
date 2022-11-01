#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<deque>
#include<bitset>
using namespace std;
//#define double long long;
int gcd(int i, int j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
typedef long double ld;
#define double long double
const double e = 0.000000000001;
const double pi = 3.1415926535898;
inline int getint() {
	int val = 0;
	char c;
	while ((c = getchar()) && !(c >= '0' && c <= '9'));
	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));
	return val;
}
const int INF = 2e9;
const int Y = 200100;
//const long long m = 998244353;
int cost[10240000];
int d[Y];
struct  EE
{
	int first;
	int second;
	EE(int f = 0, int s = 0) {
		first = f;
		second = s;
	}
};
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	// freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	cout.precision(15);
	int n = getint(), m = getint();
	for (int i = 0; i < m; ++i)d[i] = getint();
	int msk = m << 10;
	for (int i = 0; i < msk; ++i)cost[i] = INF;
	sort(d, d + m);
	int g = getint(), r = getint();
	deque<int>dq;
	dq.push_back(0);
	cost[0] = 0;
	while (!dq.empty()) {
		int tmp = dq.front();
		int b = tmp >> 10, os = tmp & 1023;
		dq.pop_front();
		if (b != m - 1 && os + d[b + 1] - d[b] <= g) {
			int v = (b + 1) << 10, ct = d[b + 1] - d[b];
			if (os + ct == g) {
				if (cost[v] > cost[tmp] + ct) {
					cost[v] = cost[tmp] + ct;
					dq.push_back(v);
				}
			}
			else {
				v |= os + ct;
				if (cost[v] > cost[tmp] + ct) {
					cost[v] = cost[tmp] + ct;
					dq.push_front(v);
				}
			}
		}
		if (b != 0 && os + d[b] - d[b - 1] <= g) {
			int v = (b - 1) << 10, ct = d[b] - d[b - 1];
			if (os + ct == g) {
				if (cost[v] > cost[tmp] + ct) {
					cost[v] = cost[tmp] + ct;
					dq.push_back(v);
				}
			}
			else {
				v |= os + ct;
				if (cost[v] > cost[tmp] + ct) {
					cost[v] = cost[tmp] + ct;
					dq.push_front(v);
				}
			}
		}
	}
	long long res = INF;
	m = (m - 1) << 10;
	for (int i = 0; i < g; ++i) {
		res = min(res, (long long)cost[i + m]);
	}
	if (res == INF) {
		cout << -1;
	}
	else {
		long long ct = res;
		ct += res / g * r;
		if (res % g == 0)ct -= r;
		res = ct;
		cout << res;
	}
	return 0;
}