#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define x second
#define y first

using namespace std;

typedef pair<int, int> pii;

int64_t det(const pii &a, const pii &b, const pii &c) {
    return int64_t(c.x - a.x) * (c.y - b.y) * a.y * b.x - int64_t(c.y - a.y) * (c.x - b.x) * a.x * b.y;
}

int main() {
    int n;
    cin >> n;
    vector<pii> p;
    p.reserve(n + 2);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        p.emplace_back(x, y);
    }
    vector<pii> P = p;
    p.emplace_back(0, 10001);
    p.emplace_back(10001, 0);
    sort(all(p));
    vector<pii> ch;
    int k = -1;
    ch.reserve(n + 2);
    for (auto q : p) {
        for (; k > 0 && (ch[k].x == q.x || det(ch[k - 1], ch[k], q) < 0); --k)
            ch.pop_back();
        ch.push_back(q);
        ++k;
    }
    sort(all(ch));
    for (int i = 0; i < n; ++i)
        if (binary_search(all(ch), P[i]))
            printf("%d ", i + 1);
    return 0;
}