#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
struct point {
	int x, y, z, num;
	bool operator <(const point &p)const {
		return x != p.x ? x < p.x : y != p.y ? y < p.y : z < p.z;
	}
}w[50100];
set<point>Set;
int n;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d", &w[i].x, &w[i].y, &w[i].z);
		w[i].num = i;
		Set.insert(w[i]);
	}

	int INF = 1e9;
	while (!Set.empty()) {
		auto it = Set.begin();
		point t = *it, nxt;
		Set.erase(it);
		it = Set.begin();
		int nx = it->x;
		point u = { nx,t.y,-INF };
		auto it2 = Set.lower_bound(u);
		if (it2 == Set.end() || it2->x != nx) it2--;
		int ny = it2->y;
		point u2 = { nx, ny, t.z };
		auto it3 = Set.lower_bound(u2);
		if(it3 == Set.end() || it3->x != nx || it3->y != ny) {
			it3--;
		}
		nxt = *it3;
		printf("%d %d\n", t.num, nxt.num);
		Set.erase(it3);
	}
}