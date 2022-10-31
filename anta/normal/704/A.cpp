#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct RemoveNext {
	vector<int> data;

	void init(int n) {
		data.assign(n, -1);
	}

	int get(int i) {
		int a = i, b, c = i;
		while((b = data[a]) >= 0) a = b;
		while((b = data[c]) >= 0) data[c] = a, c = b;
		return a;
	}

	void remove(int i) {
		data[i] = i + 1;
	}
};


int main() {
	int n; int q;
	while(~scanf("%d%d", &n, &q)) {
		vector<bool> read(q + 1);
		vector<vi> notifications(n);
		vector<int> index(n, 0);
		int unread = 0;
		int total = 0;
		int maxT = 0;
		for(int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int x;
				scanf("%d", &x), -- x;
				notifications[x].push_back(total);
				++ total, ++ unread;
			} else if(ty == 2) {
				int x;
				scanf("%d", &x), -- x;
				const vi &v = notifications[x];
				for(; index[x] != v.size(); ++ index[x]) {
					unread -= !read[v[index[x]]];
					read[v[index[x]]] = true;
				}
			} else if(ty == 3) {
				int t;
				scanf("%d", &t);
				for(; maxT < t; ++ maxT) {
					unread -= !read[maxT];
					read[maxT] = true;
				}
			} else abort();
			printf("%d\n", unread);
		}
	}
	return 0;
}