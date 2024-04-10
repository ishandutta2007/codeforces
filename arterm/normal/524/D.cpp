#include <bits/stdc++.h>

using namespace std;

const int M = 100100;

int n, m, t;
int ex[M], b[M];
vector<int> e[M], ans;

void read() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int tim = ss + 60 * (mm + 60 * hh);
        b[tim]++;
    }
}

void kill() {
    int x = 0;
    int online = 0;
    int mx = 0;
    int lastGuy = -1;
    for (int i = 0; i < M; ++i) {

        for (auto x : e[i])
            if (ex[x] == i) {
                --online;
                ex[x] = -102102;
            }

        for (int j = 0; j < b[i]; ++j)
            if (online < m) {
                ++online;
                mx = max(online, mx);
                ex[x] = i + t;
                e[ex[x]].push_back(x);
                lastGuy = x;
                ans.push_back(x);
                ++x;
            } else {
                ex[lastGuy] = i + t;
                e[ex[lastGuy]].push_back(lastGuy);
                ans.push_back(lastGuy);
            }
    }

    if (mx == m) {
        cout << x << "\n";
        for (auto x : ans)
            cout << x + 1 << "\n";
    } else
        cout << "No solution\n";
}

int main() {
    read();
    kill();
    return 0;
}