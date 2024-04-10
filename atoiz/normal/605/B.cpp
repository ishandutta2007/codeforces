#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

struct Edge
{
    int w, i;
    bool b = 0;
    Edge() {}
    Edge(int w, bool b, int i): w(w), b(b), i(i) {}
    bool operator< (const Edge &e) const
    {
    	if (w == e.w) return b > e.b;
        return w < e.w;
    }
};

void nxt(int& u, int& v)
{
    if (u < v-2) ++u;
    else u = 1, ++v;
}

void wrong()
{
    printf("-1");
    exit(0);
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int w, b;
		cin >> w >> b;
        edges[i] = Edge(w, b, i);
    }
	sort(edges.begin(), edges.end());

    int numV = 1, u = 1, v = 3;
    vector< pair<int, int> > points(m);

    for (int i = 0; i < m; ++i) {
        if (edges[i].b) {
            points[edges[i].i] = make_pair(numV, numV + 1), ++numV;
        } else {
            if (v > numV) wrong();
            points[edges[i].i] = make_pair(u, v);
			nxt(u, v);
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << points[i].first << ' ' << points[i].second << endl;
    }
}