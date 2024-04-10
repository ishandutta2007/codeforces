#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int d[1111][2222][4];

const int M = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= M) {
        a -= M;
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    d[1][1][0] = d[1][1][3] = d[1][2][1] = d[1][2][2] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int m = 0; m < 4; m++) {
                for (int nm = 0; nm < 4; nm++) {
                    int nj;
                    if ((m ^ nm) == 3) {
                        if (nm == 1 || nm == 2) {
                            nj = j + 2;
                        } else {
                            nj = j + 1;
                        }
                    } else if ((m ^ nm) == 0) {
                        nj = j;
                    } else {
                        if (nm == 0 || nm == 3) {
                            nj = j;
                        } else {
                            nj = j + 1;
                        }
                    }
                    add(d[i + 1][nj][nm], d[i][j][m]);
                }
            }
        }
    }

//    for (int i = 0; i < 4; i++) {
//        cerr << d[2][3][i] << endl;
//    }
//    cerr << endl;
//1 2
//    for (int i = 0; i < 4; i++) {
//        cerr << d[3][4][i] << endl;
//    }
//    cerr << endl;


    int ans = 0;
    for (int i = 0; i < 4; i++) {
        add(ans, d[n][k][i]);
    }

    cout << ans;

    return 0;
}//ontzjf