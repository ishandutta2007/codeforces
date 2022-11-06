#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;


const int MxN = 109;
int n, m;
string a[MxN + 9];
vector<vector<int>> output;

void flip(char &c) {
    c = '0' + '1' - c;
}

void flip(int x1, int y1, int x2, int y2, int x3, int y3) {
    flip(a[x1][y1]);
    flip(a[x2][y2]);
    flip(a[x3][y3]);
    output.push_back(vector<int>{x1, y1, x2, y2, x3, y3});
}

void rem_row() {
    for (int j = m - 1; j >= 0; --j) {
        if (a[n - 1][j] == '1') {
            int x1 = n - 1;
            int y1 = j;
            if (j == 0) {
                int x2 = n - 2;
                int y2 = 0;
                int x3 = n - 2;
                int y3 = 1;
                flip(x1, y1, x2, y2, x3, y3);
            } else {
                int x2 = n - 1;
                int y2 = j - 1;
                int x3 = n - 2;
                int y3 = j - 1;
                flip(x1, y1, x2, y2, x3, y3);
            }
        }
    }
    --n;
}

void rem_col() {
    for (int i = n - 1; i >= 0; --i) {
        if (a[i][m - 1] == '1') {
            int y1 = m - 1;
            int x1 = i;
            if (i == 0) {
                int y2 = m - 2;
                int x2 = 0;
                int y3 = m - 2;
                int x3 = 1;
                flip(x1, y1, x2, y2, x3, y3);
            } else {
                int y2 = m - 1;
                int x2 = i - 1;
                int y3 = m - 2;
                int x3 = i - 1;
                flip(x1, y1, x2, y2, x3, y3);
            }
        }
    }
    --m;
}

void f() {
    output.clear();

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    while (n > 2 || m > 2) {
        if (n > m) {
            rem_row();
        } else {
            rem_col();
        }
    }

    for (int rep = 0;; ++rep) {
        vector<pair<int, int>> v0, v1;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                    (a[i][j] == '1' ? v1 : v0).push_back({i, j});

        if (v1.empty())
            break;
        assert(rep < 4);
        if(v1.size() >= 3) {
            flip(v1[0].first, v1[0].second, v1[1].first, v1[1].second, v1[2].first, v1[2].second);
        } else if(v1.size() == 2) {
            flip(v1[0].first, v1[0].second, v0[0].first, v0[0].second, v0[1].first, v0[1].second);
            flip(v1[1].first, v1[1].second, v0[0].first, v0[0].second, v0[1].first, v0[1].second);
        } else if(v1.size() == 1) {
            flip(v1[0].first, v1[0].second, v0[0].first, v0[0].second, v0[1].first, v0[1].second);
        } else {
            assert(false);
        }
    }

    cout << output.size() << '\n';
    for (auto v : output) {
        for (int x:  v)
            cout << x + 1 << ' ';
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while (t--)f();

    return 0;
}