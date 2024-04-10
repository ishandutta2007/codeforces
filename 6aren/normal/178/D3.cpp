#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int REP = 1000;

long long Rand(long long l, long long h) {
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int n, s;

long long calc(vi &v) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int temp1 = 0;
        int temp2 = 0;
        for (int j = 0; j < n; j++) {
            temp1 += v[i * n + j];
            temp2 += v[i + j * n];
        }
        res += abs(temp1 - s) + abs(temp2 - s);
    }
    int temp1 = 0;
    int temp2 = 0;
    for (int i = 0; i < n; i++) {
        temp1 += v[i * n + i];
        temp2 += v[i * n + n - 1 - i];
    }
    return res + abs(temp1 - s) + abs(temp2 - s);
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vi v;
    for (int i = 1; i <= n * n; i++) {
        int u;
        cin >> u;
        v.pb(u);
        s += u;
    }
    s /= n;
    if (n == 1) {
        cout << s << endl << s;
        return 0;
    }
    while (1) {
        random_shuffle(all(v));
        for (int rep = 1; rep < REP; rep++) {
            int p = Rand(0, v.size() - 1);
            int q = Rand(0, v.size() - 1);
            while (q == p) {
                q = Rand(0, v.size() - 1);
            }
            long long cur = calc(v);
            swap(v[p], v[q]);
            long long nx = calc(v);
            if (cur < nx) {
                swap(v[p], v[q]);
            }
            // for (auto u : v) {
            //     cout << u << ' ';
            // }
            // cout << calc(v);
            // cout << '\n';
            if (calc(v) == 0) {
                cout << s << '\n';
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << v[i * n + j] << ' ';
                    }
                    cout << '\n';
                }
                exit(0);
            }
        }
    }
    return 0;
}