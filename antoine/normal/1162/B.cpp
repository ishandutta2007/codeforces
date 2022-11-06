#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int a[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> a(2, vector<vector<int>>(n, vector<int>(m)));
    for (auto &&vv: a)
        for (auto &&v: vv)
            for (int &x : v)
                cin >> x;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[0][i][j] > a[1][i][j])
                swap(a[0][i][j], a[1][i][j]);


    for (int r = 0; r < 2; ++r)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                bool b1 = i && a[r][i - 1][j] >= a[r][i][j];
                bool b2 = j && a[r][i][j - 1] >= a[r][i][j];
                if (b1 || b2) {
                    cout << "Impossible";
                    return 0;
                }
            }

    cout << "Possible";
    return 0;
}