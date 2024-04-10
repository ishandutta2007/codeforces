#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define x first
#define y second

const int MAXN = 200005;

int N;
pii p[MAXN];
vector < pii > V, hull;
map <pii, bool> winner;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d%d", &p[i].x, &p[i].y);
}

bool bad(pii a, pii b, pii c) {
    return (ll)b.x * c.x * a.y * (c.y - b.y) + (ll)c.x * a.x * b.y * (a.y - c.y) + (ll)a.x * b.x * c.y * (b.y - a.y) < 0;
}

bool ok(int pos) {
    if (!pos) return 1;
    pii a = hull[pos];
    pii b = hull[pos - 1];
    if (a.x < b.x) return a.y > b.y;
    if (a.y < b.y) return 0;  
    if (pos + 1 == hull.size()) return 1;
    return a.x > hull[pos + 1].x;
}

void solve() {
    for (int i = 0; i < N; i++)
        V.push_back(p[i]);
    sort(V.begin(), V.end(), greater < pii > ());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    
    for (int i = 0; i < V.size(); i++) {
        while (hull.size() > 1 && bad(hull[hull.size() - 2], hull.back(), V[i]))
            hull.pop_back();
        hull.push_back(V[i]);
    }

    for (int i = 0; i < hull.size(); i++) 
        winner[hull[i]] = ok(i);
    
    for (int i = 0; i < N; i++)
        if (winner[p[i]]) printf("%d ", i + 1);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}