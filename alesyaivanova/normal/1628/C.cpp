#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1009;
int a[maxn][maxn];
int n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in_field(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int get_sum(int i, int e) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
        int x = i + dx[j];
        int y = e + dy[j];
        if (in_field(x, y)) {
            sum += a[x][y];
        }
    }
    return sum % 2;
}

void gen() {
    for (int e = 0; e < n; e++) {
        a[0][e] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int e = 0; e < n; e++) {
            a[i][e] = 0;
            if (get_sum(i - 1, e) == 0) {
                a[i][e] = 1;
            }
        }
    }
}

void solve() {
    cin >> n;
    gen();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < n; e++) {
            int x;
            cin >> x;
            if (a[i][e]) {
                sum ^= x;
            }
        }
    }
    cout << sum << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*
000000
111111
011110
110011
011110
111111

11111111
01111110
11000011
01100110
11000011
01111110
11111111
00000000

1111111111
0111111110
1100000011
0110000110
1100110011
0110000110
1100000011
0111111110
1111111111
0000000000
*/