#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
vector <pii> e1, e2;
pii p[MAXN];

ll ccw(pii a, pii b, pii c) {
	return (ll)a.first * (b.second - c.second) + (ll)b.first * (c.second - a.second) + (ll)c.first * (a.second - b.second);
}

ll sqr(int x) {
	return (ll)x * x;
}

ll dist(pii a, pii b) {
	return sqr(a.first - b.first) + sqr(a.second - b.second);
}

vector <pii> get_hull(int n) {
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
	
	sort(p, p + n);
	
	vector <pii> g;
	for (int i = 0; i < n; i++) {
		while (g.size() > 1 && ccw(g[(int)g.size() - 2], g.back(), p[i]) >= 0)
			g.pop_back();
		g.push_back(p[i]);
	}
	
	vector <pii> d;
	for (int i = n - 1; i >= 0; i--) {
		while (d.size() > 1 && ccw(d[(int)d.size() - 2], d.back(), p[i]) >= 0)
			d.pop_back();
		d.push_back(p[i]);
	}
	
	vector <pii> hull;
	for (int i = 1; i < g.size(); i++)
		hull.push_back(g[i]);
	
	for (int i = 1; i < d.size(); i++)
		hull.push_back(d[i]);
	
	return hull;
}

void load() {	
	scanf("%d%d", &N, &M);
	e1 = get_hull(N);
	e2 = get_hull(M);
}

vector <pll> get(vector <pii> v) {
	int n = v.size();
	vector <pll> res;
	for (int i = 0; i < n; i++)
		res.push_back({dist(v[i], v[(i + 1) % n]), dist(v[i], v[(i + 2) % n])});
	return res;
}

vector <pll> lyndon(vector <pll> v) {
  int n = v.size(), i = 0, j = 1, k;
  while (j < n) {
    for (k = 0; k < n && v[(i + k) % n] == v[(j + k) % n]; k++);
    if (v[(i + k) % n] <= v[(j + k) % n]) 
      j += k + 1;
    else {
      i += k + 1;
      if (i < j)
        i = j++;
      else
        j = i + 1;
    }
  }
  rotate(v.begin(), v.begin() + i, v.end());
  return v;
}

bool rot(vector <pll> v1, vector <pll> v2) {
	return lyndon(v1) == lyndon(v2);
}

bool solve() {
	vector <pll> v1 = get(e1);
	vector <pll> v2 = get(e2);

	if (rot(v1, v2))
		return true;
	
	reverse(v2.begin(), v2.end());

	return rot(v1, v2);
}

int main() {
	load();
	puts(solve() ? "YES" : "NO");
	return 0;
}