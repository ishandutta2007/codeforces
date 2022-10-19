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
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int kek = 0; kek < n; kek++) {
        vector<int> a(kek + 1);
        for (int i = 0; i <= kek; i++) {
            a[i] = arr[i];
        }
        sort(a.begin(), a.end());
        int hh = 0;
        for (int i = kek; i >= 0; i -= 2) {
            hh += a[i];
        }
        if (hh > h) {
            cout << kek << endl;
            return 0;
        }
    }
    cout << n << endl;


    return 0;
}