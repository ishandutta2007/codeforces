#include <bits/stdc++.h>
using namespace std;

const int MAXN = 155;

typedef vector <int> poly;
typedef pair <poly, poly> pp;

vector <pp> v[MAXN];

poly mul(poly p, int a, int b) {
	poly ret;
	for (int i = 0; i <= p.size(); i++)
		ret.push_back(a * (i ? p[i - 1] : 0) + b * (i < p.size() ? p[i] : 0));
	return ret;
}

poly add(poly p, poly q) {
	poly ret;
	for (int i = 0; i < max(p.size(), q.size()); i++)
		ret.push_back((i < p.size() ? p[i] : 0) + (i < q.size() ? q[i] : 0));
	return ret;
}

bool good(poly p) {
	for (auto it : p)
		if (abs(it) > 1)
			return false;
	return true;
}

void output(poly p) {
	for (auto &it : p)
		it *= p.back();
	
	printf("%d\n", (int)p.size() - 1);
	for (auto it : p)
		printf("%d ", it);
	puts("");
}

int main() {
	int N;
	scanf("%d", &N);
	
	v[0].push_back({{1}, {0}});
	v[0].push_back({{-1}, {0}});
	for (int i = 1; i <= N; i++) {
		for (auto it : v[i - 1])
			for (int j = -1; j < 2; j += 2)
				for (int k = -1; k < 2; k++) {
					pp tmp = {add(mul(it.first, j, k), it.second), it.first};
					if (good(tmp.first))
						v[i].push_back(tmp);
				}
		v[i].resize(min((int)v[i].size(), 55));
	}
	
	output(v[N][0].first);
	output(v[N][0].second);

	return 0;
}