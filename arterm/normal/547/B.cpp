#include <bits/stdc++.h>

using namespace std;

const int M = 200200;

int n;
pair<int, int> a[M];
bool active[M];
int p[M], sz[M], msz, ans[M];

void ini() {
    msz = 1;
    for (int i = 0; i < M; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
}

int get(int x) {
    return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    p[x] = y;
    sz[y] += sz[x];
    msz = max(msz, sz[y]);
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    reverse(a, a + n);
}

void kill() {
    int l = 1;
    for (int i = 0; i < n; ++i) {
        int x = a[i].second;
        active[x] = true;
        if (x + 1 < n && active[x + 1]) {
            uni(x, x + 1);
        }
        if (x > 0 && active[x - 1]) {
            uni(x, x - 1);
        }
        while (l <= msz) {
            ans[l] = a[i].first;
            ++l;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ini();
    read();
    kill();
    return 0;
}