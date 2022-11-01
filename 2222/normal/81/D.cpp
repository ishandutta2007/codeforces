#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	priority_queue<pii> Q;
	int total = 0;
	REP (i, m) {
		int x;
		cin >> x;
		total += x;
		Q.push({x, i});
	}
	for (; total > n; --total) {
		auto t = Q.top();
		Q.pop();
		if (--t.X) Q.push(t);
	}
	if (total != n || Q.top().X * 2 > n) {
		puts("-1");
		return 0;
	}
	vi res;
	for (; Q.size(); ) {
		auto t = Q.top();
		Q.pop();
		if (sz(res) && res.back() == t.Y) {
			auto t2 = Q.top();
			Q.pop();
			Q.push(t);
			t = t2;
		} 
		res.pb(t.Y);
		if (--t.X) Q.push(t);
	}
	if (res[0] == res.back()) {
		FOR (i, 1, n) {
			if (res[i] != res[0] && res[i - 1] != res.back()) {
				reverse(i + all(res));
				break;
			}
		}
	}
	REP (i, n) {
		if (i) putchar(' ');
		printf("%d", res[i] + 1);
	}
	puts("");
	return 0;
}