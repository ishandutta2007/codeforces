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
		priority_queue<int, vector<int>, greater<int>> q;
		q.push(INF);
		char buf[99];
		vector<string> ans;
		rep(i, n) {
			char ty[10];
			scanf("%s", ty);
			if(*ty == 'i') {
				int x;
				scanf("%d", &x);
				q.push(x);
				sprintf(buf, "insert %d", x), ans.push_back(buf);
			} else if(*ty == 'g') {
				int x;
				scanf("%d", &x);
				while(q.top() < x) {
					q.pop();
					sprintf(buf, "removeMin"), ans.push_back(buf);
				}
				if(x < q.top()) {
					q.push(x);
					sprintf(buf, "insert %d", x), ans.push_back(buf);
				}
				assert(q.top() == x);
				sprintf(buf, "getMin %d", x), ans.push_back(buf);
			} else if(*ty == 'r') {
				if(q.top() == INF) {
					q.push((int)1e9);
					sprintf(buf, "insert %d", (int)1e9), ans.push_back(buf);
				}
				q.pop();
				sprintf(buf, "removeMin"), ans.push_back(buf);
			} else abort();
		}
		printf("%d\n", (int)ans.size());
		for(int i = 0; i < (int)ans.size(); ++ i)
			puts(ans[i].c_str());
	}
	return 0;
}