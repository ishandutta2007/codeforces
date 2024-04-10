#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 50 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;

struct Point {
    int x, y;

    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

struct Node {
    vector< pair<int, int> > vec;
    vector<int> maxup, pos1, pos2;
};

Node st[4 * MAXN];
pair<Point, int> vert[MAXN], hor;
int n;

void buildst(int v, int tl, int tr) {
    st[v].vec.clear();
    st[v].maxup.clear();
    st[v].pos1.clear();
    st[v].pos2.clear();
    if(tl == tr - 1) {
        st[v].vec.push_back(make_pair(vert[tl].first.y,
                                      vert[tl].first.y + vert[tl].second));
        st[v].maxup.push_back(vert[tl].first.y + vert[tl].second);
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    size_t p1 = 0, p2 = 0;
    while(p1 < st[2 * v].vec.size() && p2 < st[2 * v + 1].vec.size())
        if(st[2 * v].vec[p1] < st[2 * v + 1].vec[p2]) {
            st[v].vec.push_back(st[2 * v].vec[p1]);
            st[v].pos1.push_back(p1);
            st[v].pos2.push_back(p2 - 1);
            p1++;
        }
        else {
            st[v].vec.push_back(st[2 * v + 1].vec[p2]);
            st[v].pos1.push_back(p1 - 1);
            st[v].pos2.push_back(p2);
            p2++;
        }
    while(p1 < st[2 * v].vec.size()) {
        st[v].vec.push_back(st[2 * v].vec[p1]);
        st[v].pos1.push_back(p1);
        st[v].pos2.push_back(p2 - 1);
        p1++;
    }
    while(p2 < st[2 * v + 1].vec.size()) {
        st[v].vec.push_back(st[2 * v + 1].vec[p2]);
        st[v].pos1.push_back(p1 - 1);
        st[v].pos2.push_back(p2);
        p2++;
    }
    st[v].maxup.resize(st[v].vec.size());
    st[v].maxup[0] = st[v].vec[0].second;
    for(size_t i = 1; i < st[v].vec.size(); i++)
        st[v].maxup[i] = max(st[v].vec[i].second, st[v].maxup[i - 1]);
}

bool get1(int v, int tl, int tr, int l, int r, int p, int m) {
    if(vert[tl].first.x == l && vert[tr - 1].first.x == r)
        return st[v].maxup[p] >= hor.first.y + m;
    if(l > r)
        return false;
    int tm = (tl + tr) / 2;
    bool res1 = false, res2 = false;
    if(st[v].pos1[p] >= 0)
        res1 = get1(2 * v, tl, tm,
                    l, min(r, vert[tm - 1].first.x), st[v].pos1[p], m);
    if(st[v].pos2[p] >= 0)
        res2 = get1(2 * v + 1, tm, tr,
                    max(l, vert[tm].first.x), r, st[v].pos2[p], m);
    return res1 || res2;
}

bool get0(int m) {
    vector< pair<int, int> >::iterator it =
        lower_bound(st[1].vec.begin(), st[1].vec.end(),
                    make_pair(hor.first.y - m + 1, 0));
    int p = distance(st[1].vec.begin(), it);
    p--;
    if(p < 0)
        return false;
    return get1(1, 0, n, max(vert[0].first.x, hor.first.x + m),
                min(vert[n - 1].first.x, hor.first.x + hor.second - m), p, m);
}

int get() {
    int l = 0, r = INF;
    while(l < r - 1) {
        int m = (l + r) / 2;
        if(get0(m))
            l = m;
        else
            r = m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> vert[i].first.x >> vert[i].first.y >> vert[i].second;
    sort(vert, vert + n);
    buildst(1, 0, n);
    int ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> hor.first.x >> hor.first.y >> hor.second;
        ans = max(ans, get());
    }
    cout << ans << '\n';
    return 0;
}