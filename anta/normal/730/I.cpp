#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int N; int L; int K;
	while(~scanf("%d%d%d", &N, &K, &L)) {
		vector<int> A(N);
		for(int i = 0; i < N; ++ i)
			scanf("%d", &A[i]);
		vector<int> B(N);
		for(int i = 0; i < N; ++ i)
			scanf("%d", &B[i]);
		vector<pair<int, int>> xs(N), ys(N);
		rep(i, N) {
			xs[i] = make_pair(-A[i], i);
			ys[i] = make_pair(-B[i], i);
		}
		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());
		vector<int> flag(N);
		rep(i, K)
			flag[xs[i].second] = 1;
		multiset<pair<int, int>> rema, remba, remb;
		rep(i, N) {
			int a = A[i], b = B[i];
			if(flag[i] == 1) {
				remba.insert(make_pair(b - a, i));
			} else if(flag[i] == 0) {
				rema.insert(make_pair(a, i));
				remb.insert(make_pair(b, i));
			}
		}
		rep(kk, L) {
			pii ma(-INF, -1);
			pair<int, int> c = rema.empty() ? make_pair(-INF, -1) : *rema.rbegin();
			if(!remba.empty()) {
				ma = *remba.rbegin();
				ma.first += c.first;
			}
			if(!remb.empty())
				amax(ma, *remb.rbegin());
			int i = ma.second;
			if(flag[i] == 1) {
				int a = A[c.second], b = B[c.second];
				rema.erase(make_pair(a, c.second));
				remb.erase(make_pair(b, c.second));
				remba.insert(make_pair(b - a, c.second));
				flag[c.second] = 1;
			}
			int a = A[i], b = B[i];
			rema.erase(make_pair(a, i));
			remb.erase(make_pair(b, i));
			remba.erase(make_pair(b - a, i));
			flag[i] = 2;
		}
		ll total = 0;
		vector<int> ans[2];
		rep(i, N) if(flag[i] != 0) {
			total += flag[i] == 1 ? A[i] : B[i];
			ans[flag[i] - 1].push_back(i);
		}
		printf("%lld\n", total);
		rep(k, 2) {
			for(int i = 0; i < (int)ans[k].size(); ++ i) {
				if(i != 0) putchar(' ');
				printf("%d", ans[k][i] + 1);
			}
			puts("");
		}
	}
	return 0;
}