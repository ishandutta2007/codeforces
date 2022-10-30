#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

template<typename T>
vector<pair<T, int> > runLength(const T a[], int n) {
	vector<pair<T, int> > r;
	if(n <= 0) return r;
	int cnt = 0;
	for(int i = 0; i <= n; i ++) {
		if(i == n || (i != 0 && a[i] != a[i - 1])) {
			r.push_back(make_pair(a[i - 1], cnt));
			cnt = 0;
		}
		cnt ++;
	}
	return r;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		string s;
		cin >> s;
		auto v = runLength(s.c_str(), n);
		vi ans;
		for(auto p : v) if(p.first == 'B')
			ans.push_back(p.second);
		printf("%d\n", (int)ans.size());
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}