#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2 * 100000 + 5;

int N;
int v[NMAX];

bool do_solve(bool rv) {
    bool done = false;
    int minimum = v[1] - 1, where = 1;
    for (int i = 2; i <= N && !done; ++i) {
        if (v[i] - i - minimum >= 1) {
            cout << "YES\n";
            if (!rv) {
                cout << where << ' ' << i << '\n';
            } else {
                cout << N - i + 1 << ' ' << N - where + 1 << '\n';
            }
            done = true;
        }
        if (v[i] - i < minimum) {
            minimum = v[i] - i;
            where = i;
        }
    }
    return done;
}

void test() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }
    if (!do_solve(false)) {
        reverse(v + 1, v + N + 1);
        if (!do_solve(true)) {
            cout << "NO\n";
        }
    }
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        test();
    }
    return 0;
}