#include <iostream>
#include <algorithm>

using namespace std;

struct Dsu {
    int p, r, c;
};

const int MAXN = 3005;
pair<int, pair<int, int> > e[MAXN];
Dsu dsu[MAXN];
int sum;

int get(int x) {
    return x == dsu[x].p? x : dsu[x].p = get(dsu[x].p);
}

bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(dsu[x].r < dsu[y].r)
        swap(x, y);
    dsu[y].p = x;
    dsu[x].r += dsu[y].r;
    dsu[x].c += dsu[y].c;
    return dsu[x].r <= sum - dsu[x].c;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
        e[i].second.first--;
        e[i].second.second--;
    }
    for(int i = 0; i < n; i++) {
        dsu[i].p = i;
        dsu[i].r = 1;
        cin >> dsu[i].c;
        sum += dsu[i].c;
    }
    sort(e, e + n - 1);
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans = e[i].first;
        if(!unite(e[i].second.first, e[i].second.second))
            break;
    }
    cout << ans << '\n';
    return 0;
}