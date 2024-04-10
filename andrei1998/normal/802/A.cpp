#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400000;

int values[MAXN], last[MAXN];
int to[MAXN];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
        values[i]--;
    }

    memset(last, -1, sizeof last);
    for (int i = n - 1; i >= 0; --i) {
        if (last[values[i]] == -1) {
            to[i] = n + i;
        } else {
            to[i] = last[values[i]];
        }
        last[values[i]] = i;
    }

    int answer = 0, used = 0;
    set<int> q;
    for (int i = 0; i < n; ++i) {
        if (q.find(i) == q.end()) {
            ++answer;
            if (used == k) {
                q.erase(*q.rbegin());
                --used;
            }
            q.insert(to[i]);
            ++used;
        } else {
            q.erase(i);
            q.insert(to[i]);
        }
    }
    cout << answer << '\n';

    return 0;
}