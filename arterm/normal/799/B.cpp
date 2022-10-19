#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

int p[M];
int a[M], b[M];
vector<int> x[3];
bool used[M];
int n;
int m;

int id(int x) {
    return lower_bound(p, p + n, x) - p;
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i < n; ++i) {
        --a[i], --b[i];
        x[a[i]].push_back(p[i]);
        if (b[i] != a[i])
            x[b[i]].push_back(p[i]);
    }
}

void kill() {
    sort(p, p + n);
    for (int i = 0; i < 3; ++i) {
        sort(all(x[i]), greater<int>());
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        --c;
        bool found = false;
        while (!x[c].empty()) {
            int cur = id(x[c].back());
            x[c].pop_back();
            if (used[cur])
                continue;
            else {
                found = true;
                used[cur] = true;
                cout << p[cur] << " ";
                break;
            }
        }
        if (!found)
            cout << "-1 ";
    }
    cout << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}