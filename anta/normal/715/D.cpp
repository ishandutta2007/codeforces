#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

//#include "GeoVisClient.h"
pair<pii, pii> transposed(pair<pii, pii> a) {
	pii p = a.first, q = a.second;
	return{ {p.second,p.first}, {q.second,q.first} };
}

int main() {
	//GeoVisClient gv;
	long long D;
	while(~scanf("%lld", &D)) {
		vector<pair<pii,pii>> ans;
		ll x = D;
		rep(i, 38) {
			if(x % 3 <= 1)
				ans.push_back({ { i + 1, 3 + i },{ i + 1, 3 + i + 1 } });
			if(x % 3 == 0)
				ans.push_back({ { 3 + i, i + 1 },{ 3 + i + 1, i + 1 } });
			if(i < 36) {
				ans.push_back({ { i + 1, 3 + i + 2 },{ i + 1, 3 + i + 3 } });
				ans.push_back(transposed(ans.back()));
			}
			if(i < 37) {
				ans.push_back({ { i + 1, 3 + i + 1 },{ i + 2, 3 + i + 1 } });
				ans.push_back(transposed(ans.back()));
			} else {
				ans.push_back({ { i + 2, 3 + i },{ i + 2, 3 + i + 1 } });
				ans.push_back(transposed(ans.back()));
				ans.push_back({ { i + 3, 3 + i },{ i + 3, 3 + i + 1 } });
				ans.push_back(transposed(ans.back()));
			}
			x /= 3;
		}
		/*
		gv.clear();
		for(auto w : ans) {
			auto p = w.first, q = w.second;
			if(p.first == q.first) {
				assert(p.second + 1 == q.second);
				gv.line(p.first - 1, p.second, p.first, p.second);
			} else {
				assert(p.second == q.second && p.first + 1 == q.first);
				gv.line(p.first, p.second - 1, p.first, p.second);
			}
		}
		*/
		puts("41 41");
		printf("%d\n", (int)ans.size());
		for(auto w : ans) {
			auto p = w.first, q = w.second;
			printf("%d %d %d %d\n", p.first, p.second, q.first, q.second);
		}
	}
	return 0;
}