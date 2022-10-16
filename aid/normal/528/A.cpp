#include <iostream>

using namespace std;

struct Dsu {
    int p, ts;
};

const int MAXN = 200 * 1000 + 5;
long long ans[MAXN];
int maxlen[2];
pair<char, int> q[MAXN];
char cx[MAXN], cy[MAXN];
Dsu dsu[2][MAXN];

int get(int t, int x) {
    return x == dsu[t][x].p? x : dsu[t][x].p = get(t, dsu[t][x].p);
}

void unite(int t, int x, int y) {
    x = get(t, x);
    y = get(t, y);
    if(x == y)
        return;
    if(dsu[t][x].ts < dsu[t][y].ts)
        swap(x, y);
    dsu[t][y].p = x;
    dsu[t][x].ts += dsu[t][y].ts;
    maxlen[t] = max(maxlen[t], dsu[t][x].ts);
}

int main() {
    ios_base::sync_with_stdio(false);
    int w, h, n;
    cin >> w >> h >> n;
    for(int i = 0; i < n; i++) {
        cin >> q[i].first >> q[i].second;
        if(q[i].first == 'V')
            cx[q[i].second] = true;
        else
            cy[q[i].second] = true;
    }
    for(int i = 0; i < w; i++) {
        dsu[0][i].p = i;
        dsu[0][i].ts = 1;
    }
    for(int i = 0; i < h; i++) {
        dsu[1][i].p = i;
        dsu[1][i].ts = 1;
    }
    maxlen[0] = 1;
    maxlen[1] = 1;
    for(int i = 1; i < w; i++)
        if(!cx[i])
            unite(0, i - 1, i);
    for(int i = 1; i < h; i++)
        if(!cy[i])
            unite(1, i - 1, i);
    for(int i = n - 1; i >= 0; i--) {
        ans[i] = (long long)maxlen[0] * maxlen[1];
        if(q[i].first == 'V')
            unite(0, q[i].second - 1, q[i].second);
        else
            unite(1, q[i].second - 1, q[i].second);
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    return 0;
}