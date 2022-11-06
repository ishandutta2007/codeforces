#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int n;
const int MxN = (int) 3e5 + 9;
int a[MxN + 9];
int pos[MxN + 9];
vector<pair<int, int>> res;

void sw(const int i, const int j) {
    if (i == j)
        return;
    if (i > j) {
        sw(j, i);
        return;
    }

    assert(j - i >= n / 2);
    swap(a[i], a[j]);
    res.push_back({i, j});
    assert(res.size() <= 5 * n);
}

void sw5(const int i, const int j) {
    if(i == j)
        return;
    if (i > j) {
        sw5(j, i);
        return;
    }

    if (j - i >= n / 2)
        sw(i, j);
    else if(i > n/2) {
        sw(1, i);
        sw(1, j);
        sw(1, i);
    } else if(j <= n/2) {
        sw(j, n);
        sw(i, n);
        sw(j, n);
    } else {
        cerr << i << ' ' << j << ' ' << n << endl;
        assert(1 < i && j < n);
        sw(1, j);
        sw(i, n);
        sw(1, n);
        sw(1, j);
        sw(i, n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        while (a[i] != i)
            sw5(i, a[i]);
    }
    for(int i = 1; i <= n; ++i)
        assert(a[i] == i);

    cout << res.size() << '\n';
    for (auto &&p : res)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}