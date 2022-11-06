#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const int n = 999;
int kx, ky;
int x[1111];
int y[1111];
int a[1111][1111];

void move(int nx, int ny) {
    if (a[nx][ny]) {
        cout << nx + 1 << " " << ky + 1 << endl;
        exit(0);
    }

    cout << nx + 1 << " " << ny + 1 << endl;
    int k, rx, ry;
    cin >> k >> rx >> ry;
    if (k <= 0) {
        exit(k + 1);
    }
    --k; --rx; --ry;
    a[x[k]][y[k]] = 0;
    x[k] = rx;
    y[k] = ry;
    a[x[k]][y[k]] = 1;

    kx = nx;
    ky = ny;
}

int dx[4] = {-1, 1, 1, -1};
int dy[4] = {-1, -1, 1, 1};

int main() {
#ifdef VSE
//    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    cin >> kx >> ky;
    --kx; --ky;
    for (int i = 0; i < 2 * n / 3; i++) {
        cin >> x[i] >> y[i];
        --x[i]; --y[i];
        a[x[i]][y[i]] = 1;
    }

    while (kx != n / 2 || ky != n / 2) {
        int nx = kx, ny = ky;
        if (nx < n / 2) {
            nx++;
        } else if (nx > n / 2) {
            nx--;
        }
        if (ny < n / 2) {
            ny++;
        } else if (ny > n / 2) {
            ny--;
        }

        move(nx, ny);
    }

    vector<int> cnt(4);
    for (int d = 0; d < 4; d++) {
        for (int i = kx; i >= 0 && i < n; i += dx[d]) {
            for (int j = ky; j >= 0 && j < n; j += dy[d]) {
                if (a[i][j]) {
                    cnt[d]++;
                }
            }
        }
    }

    int p = min_element(begin(cnt), end(cnt)) - begin(cnt);
    p = (p + 2) % 4;

    while (true) {
        move(kx + dx[p], ky + dy[p]);
    }



    return 0;
}//ercjla