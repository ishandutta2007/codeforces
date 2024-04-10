#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

typedef double ftype;
typedef complex<ftype> point;

const ftype eps = 1e-6;
const ftype pi = acos(-1);

pair<ftype, ftype> get_seg(point a, ftype r) {
	ftype cp = r;
	ftype sp = sqrt(norm(a) - norm(r));
	point rot = {cp, sp};
	return {arg(a / rot), 2 * arg(rot)};
}

const int logn = 20;

int check(point *r, int n, ftype R) {
	vector<pair<ftype, ftype>> segs;
	ftype la, ra;
	for(int i = 0; i < n; i++) {
		tie(la, ra) = get_seg(r[i], R);
		segs.emplace_back(la, la + ra);
		segs.emplace_back(la + 2 * pi, la + ra + 2 * pi);
	}
	sort(all(segs));
	
	int m = segs.size();
	int next[m + 1][logn];
	fill(next[m], next[m] + logn, m);
	for(int i = m - 1; i >= 0; i--) {
		next[i][0] = next[i + 1][0];
		while(segs[next[i][0] - 1].first > segs[i].second) {
			next[i][0]--;
		}
		for(int z = 1; z < logn; z++) {
			next[i][z] = next[next[i][z - 1]][z - 1];
		}
	}
	
	int ans = n;
	for(int i = 0; i < n; i++) {
		int j = i, cur = 0;
		for(int z = logn - 1; z >= 0; z--) {
			if(next[j][z] - i < n) {
				j = next[j][z];
				 cur += 1 << z;
			}
		}
		ans = min(ans, cur + 1);
	}
	return ans;
}

int main() {
	int n, M;
	cin >> n >> M;
	point R[n];
	ftype l = 0, r = 1e6;
	for(int i = 0; i < n; i++) {
		ftype x, y;
		cin >> x >> y;
		R[i] = {x, y};
		r = min(r, abs(R[i]));
	}
	while(r - l > eps) {
		ftype m = (l + r) / 2;
		if(check(R, n, m) <= M) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << fixed << setprecision(9);
	cout << (l + r) / 2 << endl;
	return 0;
}