#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

priority_queue<int> q[4];
int n[4], t[4], k, s[4];

void read() {
    cin >> k;
    for (int i = 0; i < 3; ++i)
        cin >> n[i];
    for (int i = 0; i < 3; ++i)
        cin >> t[i];

    s[0] = 0;
    for (int i = 1; i <= 3; ++i)
        s[i] = s[i - 1] + t[i - 1];
}

void kill() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n[i]; ++j)
            q[i].push(0);

    int top[3];
    int ans = 0;
    for (int i = 0; i < k; ++i) {

        for (int j = 0; j < 3; ++j) {
            top[j] = -q[j].top();
            q[j].pop();
        }

        int st = 0;
        for (int j = 0; j < 3; ++j)
            st = max(st, top[j] - s[j]);

        ans = st + s[3];

        for (int j = 0; j < 3; ++j)
            q[j].push(-(st + s[j + 1]));
    }

    cout << ans << "\n";
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();

    return 0;
}