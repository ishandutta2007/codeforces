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
    int n;
    cin >> n;
    int l1 = 0;
    int l2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            l1 = i;
        } else {
            l2 = i;
        }
    }
    cout << min(l1, l2) + 1 << endl;
    return 0;
}