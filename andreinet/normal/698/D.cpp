#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

struct Point {
    int x, y, pos;
    Point() = default;

    Point(int _x, int _y, int _pos = -1):
        x(_x), y(_y), pos(_pos) {}
    bool operator<(const Point& o) const {
        return make_pair(x, y) < make_pair(o.x, o.y);
    }
};

struct Comparator1 {
    Point o;
    Comparator1(const Point& _o):
        o(_o) {}
    bool operator()(const Point& a, const Point& b) const {
        return make_tuple((int64_t) (a.y - o.y) * (b.x - o.x), a.x, a.y) <
               make_tuple((int64_t) (b.y - o.y) * (a.x - o.x), b.x, b.y);
    }
};

struct Comparator2 {
    Point o;
    Comparator2(const Point& _o):
        o(_o) {}
    bool operator()(const Point& a, const Point& b) const {
        return (int64_t) (a.y - o.y) * (b.x - o.x) <
               (int64_t) (b.y - o.y) * (a.x - o.x);
    }
};

vector<vector<int>> positions;
vector<vector<int>> sPoints;
vector<vector<int>> xbegin;
vector<int> portalPositions;

vector<bool> isKilled, toBeKilled;
vector<int> toKill;

vector<bool> portalUsed;

int nrToKill = 0;
bool back(int k, int pos) {
    if (nrToKill == 0) {
        return true;
    }
    if (pos == k) {
        return false;
    }
    for (int i = 0; i < k; ++i) {
        if (!portalUsed[i]) {
            for (int j = 0; j < SZ(toKill); ++j) {
                if (isKilled[toKill[j]]) {
                    continue;
                }
                int begin = portalPositions[i], end = positions[i][toKill[j]];
                if (begin < end) {
                    begin = xbegin[i][end];
                } else {
                    swap(begin, end);
                    end = xbegin[i][begin] + 1;
                    begin++;
                }
                if (end - begin > 2 * k) {
                    continue;
                }
                int cnt = 0;
                for (int k = begin; k < end; ++k) {
                    if (!toBeKilled[sPoints[i][k]]) {
                        cnt++;
                    }
                }
                int nnr = nrToKill + cnt - 1;
                if (nnr > k - pos - 1) {
                    continue;
                }
                for (int k = begin; k < end; ++k) {
                    if (!toBeKilled[sPoints[i][k]]) {
                        toKill.push_back(sPoints[i][k]);
                        toBeKilled[sPoints[i][k]] = true;
                    }
                }
                swap(nrToKill, nnr);
                isKilled[toKill[j]] = true;
                portalUsed[i] = true;
                if (back(k, pos + 1)) {
                    return true;
                }
                swap(nrToKill, nnr);
                isKilled[toKill[j]] = false;
                portalUsed[i] = false;
                while (cnt > 0) {
                    toBeKilled[toKill.back()] = false;
                    toKill.pop_back();
                    cnt--;
                }
            }
        }
    }
    return false;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector<Point> portals(k);
    for (Point& p: portals) {
        cin >> p.x >> p.y;
        p.pos = -1;
    }
    vector<Point> targets(n);
    for (int i = 0; i < n; ++i) {
        cin >> targets[i].x >> targets[i].y;
        targets[i].pos = i;
    }
    positions = vector<vector<int>>(k, vector<int>(n, -1));
    portalPositions = vector<int>(k);
    sPoints = vector<vector<int>>(k);
    xbegin = vector<vector<int>>(k);
    for (int i = 0; i < k; ++i) {
        vector<Point> aux = targets;
        aux.push_back(portals[i]);
        sort(aux.begin(), aux.end());
        int pos = 0;
        while (aux[pos].pos != -1) {
            ++pos;
        }
        Comparator1 c(portals[i]);
        sort(aux.begin(), aux.begin() + pos, c);
        sort(aux.begin() + pos + 1, aux.end(), c);
        sPoints[i] = vector<int>(SZ(aux));
        for (int j = 0; j < SZ(aux); ++j) {
            if (aux[j].pos == -1) {
                portalPositions[i] = j;
            } else {
                positions[i][aux[j].pos] = j;
            }
            sPoints[i][j] = aux[j].pos;
        }
        xbegin[i] = vector<int>(n + 1, -1);
        Comparator2 c1(portals[i]);
        for (int j = portalPositions[i] + 1, k; j < SZ(aux); j = k) {
            for (k = j; k < SZ(aux) &&
                    !c1(aux[j], aux[k]); ++k) {
                xbegin[i][k] = j;
            }
        }
        for (int j = portalPositions[i] - 1, k; j >= 0; j = k) {
            for (k = j; k >= 0 &&
                    !c1(aux[k], aux[j]); --k) {
                xbegin[i][k] = j;
            }
        }
    }
    
    isKilled = vector<bool>(n, false);
    toBeKilled = vector<bool>(n, false);
    int ans = 0;
    portalUsed = vector<bool>(n, false);
    for (int i = 0; i < n; ++i) {
        toKill.push_back(i);
        toBeKilled[i] = true;
        nrToKill = 1;
        if (back(k, 0)) {
            ans++;
        }
        toKill.clear();
        fill(toBeKilled.begin(), toBeKilled.end(), false);
        fill(isKilled.begin(), isKilled.end(), false);
        fill(portalUsed.begin(), portalUsed.end(), false);
        nrToKill = 0;
    }

    cout << ans << '\n';
}