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
	int n;
	while(~scanf("%d", &n)) {
		vector<int> r(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &r[i]);
		int x = *min_element(r.begin(), r.end());
		int K = 2;
		for(; x > 0; -- x) {
			int sum = 0;
			rep(i, n)
				sum += r[i] - x;
			int ma = *max_element(r.begin(), r.end()) - x;
			if(ma * 2 <= sum) {
				if(sum % 2 != 0)
					K = 3;
				break;
			}
		}
		printf("%d\n", x);
		vpii v(n);
		rep(i, n)
			v[i] = { r[i], i };
		sort(v.begin(), v.end());
		vector<string> ans;
		while(1) {
			sort(v.begin(), v.end());
			if(v.back().first == x) break;
			string str(n, '0');
			rep(i, K) {
				auto &p = v[v.size() - 1 - i];
				str[p.second] = '1';
				amax(-- p.first, 0);
			}
			K = 2;
			ans.push_back(str);
		}
		printf("%d\n", (int)ans.size());
		for(auto &&s : ans)
			puts(s.c_str());
	}
	return 0;
}