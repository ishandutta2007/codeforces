#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 1009;
int r[MxN + 9];
int c[MxN + 9];
int a[MxN + 9];
int b[MxN + 9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> r[i];
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = i;

    vector<array<int, 4>> res;
    for (int i = 1; i <= n; ++i) {
        int x = i, y = i;
        while (r[a[x]] != i)
            ++x;
        while (c[b[y]] != i)
            ++y;
        if (x != i || y != i) {

            res.push_back({x, i, i, y});
            swap(a[x], a[i]);
            swap(b[y], b[i]);
        }
        assert(r[a[i]] == i);
        assert(c[b[i]] == i);
    }


    cout << res.size() << '\n';
    for (auto p : res) {
        for (int x : p)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}