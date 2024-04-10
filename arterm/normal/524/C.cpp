#include <bits/stdc++.h>

using namespace std;

const int M = 5050;
int n, a[M], k;
map<int, int> d;

void read() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void pre() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= k; ++j)
            if (d.count(a[i] * j))
                d[a[i] * j] = min(d[a[i] * j], j);
            else
                d[a[i] * j] = j;
}

void kill() {
    int q;
    cin >> q;
    for (int i = 0, s; i < q; ++i) {
        cin >> s;
        int ans = k + 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= k; ++j)
                if (a[i] * j <= s && d.count(s - a[i] * j))
                    ans = min(ans, j + d[s - a[i] * j]);
        if (ans > k)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
}


int main() {
    read();
    pre();
    kill();
    return 0;
}