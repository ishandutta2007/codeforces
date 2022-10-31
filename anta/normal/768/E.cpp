#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

map<ll, int> memo[61];
int rec(int s, ll forbidden) {
	forbidden &= (1LL << (s + 1)) - 1;
	int &r = memo[s].insert(make_pair(forbidden, -1)).first->second;
	if (r != -1) return r;
	ll moves = 0;
	rer(i, 1, s) if (~forbidden >> i & 1) {
		int x = rec(s - i, forbidden | (1LL << i));
		moves |= 1LL << x;
	}
	r = 0;
	while (moves >> r & 1) ++ r;
	return r;
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		rep(k, 61) memo[k].clear();
		int sum = 0;
		rep(i, n) {
			int s;
			scanf("%d", &s);
			int x = rec(s, 0);
			sum ^= x;
		}
		bool ans = sum == 0;
		puts(ans ? "YES" : "NO");
	}
	return 0;
}