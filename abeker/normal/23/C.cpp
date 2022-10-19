#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct box {
	int a, o, id;
	void input(int _id) {
		scanf("%d%d", &a, &o);
		id = _id;
	}
	bool operator <(const box &rhs) const {
		if (a != rhs.a)
			return a < rhs.a;
		if (o != rhs.o)
			return o < rhs.o;
		return id < rhs.id; 
	}
};

int N;
box b[MAXN];

void load() {
	scanf("%d", &N);
	N = 2 * N - 1;
	for (int i = 0; i < N; i++)
		b[i].input(i + 1);
}

void solve() {
	sort(b, b + N);
	
	puts("YES");
	
	vector <box> v;
	for (int i = 0; i < N; i++)
		if (!v.empty() && v.back().o <= b[i].o) {
			printf("%d ", b[i].id);
			v.pop_back();
		}
		else 
			v.push_back(b[i]);
	
	for (int i = 0; i < v.size(); i += 2)
		printf("%d ", v[i].id);
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}