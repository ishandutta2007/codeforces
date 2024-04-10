#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;
int pos[MAXN];

int main() {
    int n, m, k, x;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x;
        pos[x] = i;
    }
    long long time = 0, p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p;
            time += pos[p];
            for (int x = 1; x <= k; x++) {
                if (pos[x] < pos[p]) {
                    pos[x]++;
                }
            }
            pos[p] = 1;
        }
    }
    cout << time << endl;
}