#include <iostream>
#include <algorithm>

using namespace std;

struct edge {
    int val;
    int pos;

    bool take;
} v[100005];

bool operator< (const edge &a, const edge &b) {
    if (a.val != b.val)
        return a.val < b.val;
    return a.take > b.take;
}

pair <int, int> nedge (int a, int b) {
    if (a == b - 2)
        return make_pair(1, b + 1);
    else
        return make_pair(a + 1, b);
}

pair <int, int> anss[100005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++ i) {
        cin >> v[i].val >> v[i].take;
        v[i].pos = i;
    }

    sort(v + 1, v + m + 1);

    pair <int, int> last(0, 2);
    int border = 1;

    bool ok = true;
    for (int i = 1; i <= m; ++ i)
        if (!v[i].take) {
            anss[v[i].pos] = nedge(last.first, last.second);
            last = nedge(last.first, last.second);

            if (last.first > border || last.second > border)
                ok = false;
        }
        else {
            anss[v[i].pos] = make_pair(border, border + 1);
            ++ border;
        }

    if (ok) {
        for (int i = 1; i <= m; ++ i)
            cout << anss[i].first << ' ' << anss[i].second << '\n';
    }
    else
        cout << "-1\n";

    return 0;
}