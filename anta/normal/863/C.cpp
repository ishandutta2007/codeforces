#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	long long K; int a; int b;
	while (~scanf("%lld%d%d", &K, &a, &b)) {
		-- a, -- b;
		vector<vector<int> > A(3, vector<int>(3));
		for (int i = 0; i < 3; ++ i) for (int j = 0; j < 3; ++ j)
			scanf("%d", &A[i][j]), -- A[i][j];
		vector<vector<int> > B(3, vector<int>(3));
		for (int i = 0; i < 3; ++ i) for (int j = 0; j < 3; ++ j)
			scanf("%d", &B[i][j]), -- B[i][j];
		struct Perm {
			array<pair<int, pair<ll, ll>>, 9> next;
			Perm() {
				rep(i, 9)
					next[i] = { i, {0, 0} };
			}
			Perm operator*(const Perm &that) {
				Perm res;
				rep(i, 9) {
					int j = next[i].first;
					res.next[i] = {
						that.next[j].first,
						{
							next[i].second.first + that.next[j].second.first,
							next[i].second.second + that.next[j].second.second,
						}
					};
				}
				return res;
			}
		};
		Perm perm;
		rep(i, 3) rep(j, 3) {
			int x = A[i][j], y = B[i][j];
			perm.next[i * 3 + j] = { x * 3 + y, {(i + 2) % 3 == j, (j + 2) % 3 == i} };
		}
		Perm x = perm, y{};
		while (K > 0) {
			if (K & 1) y = y * x;
			x = x * x;
			K >>= 1;
		}
		auto ans = y.next[a * 3 + b].second;
		printf("%lld %lld\n", ans.first, ans.second);
	}
	return 0;
}