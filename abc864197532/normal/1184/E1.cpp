#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
struct edge {
    int x, y, w;
};
vector<edge> e;
vector<int> rt;
int find(int i) {
    if (i == rt[i]) return i;
    return rt[i] = find(rt[i]);
}
int main() {
    int n, m;
    cin >> n >> m;
    rt.resize(n), iota(rt.begin(), rt.end(), 0), e.resize(m);
    for (edge &i : e) cin >> i.x >> i.y >> i.w, --i.x, --i.y;
    edge e0 = e[0];
    swap(e[0], e.back()), e.pop_back();
    sort(e.begin(), e.end(), [](edge i, edge j){return i.w < j.w;});
    for (edge i : e) {
        int x = find(i.x), y = find(i.y);
        if (x != y) rt[x] = y;
        if (find(e0.x) == find(e0.y)) return cout << i.w, 0;
    }
    cout << 1000000000;
}