//                              ___-------___
//                          _-~~             ~~-_
//                       _-~                    /~-_
//    /^\__/^\         /~  \                   /    \
//  /| O ||O |        /      \_______________/        \
// | |___||__|      /       /                \          \
// |          \    /      /                    \          \
// |   (_______) /______/                        \_________ \
// |         / /         \                      /            \
//  \         \^\\         \                  /               \     /
//    \         ||           \______________/      _-_       //\__//
//      \       ||------_-~~-_ ------------- \ --/~   ~\    || __/
//        ~-----||====/~     |==================|       |/~~~~~
//         (_(__/  ./     /                    \_\      \.
//                (_(___/                         \_____)_)
//
#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m)), b(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] != b[i][j]) {
                a[i][j] ^= 1;
                a[i + 1][j] ^= 1;
                a[i][j + 1] ^= 1;
                a[i + 1][j + 1] ^= 1;
            }
        }
    }
    if (a != b) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}