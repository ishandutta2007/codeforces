//                              ___-------___ _-~~             ~~-_
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
    string s;
    cin >> s;
    int cnt1 = (n - 11) / 2;
    int cnt2 = (n - 11) / 2;
    string res;
    for (int i = 0; i < n; i++) {
        if (s[i] == '8') {
            if (cnt1) {
                cnt1--;
            } else {
                res += s[i];
            }
        } else {
            if (cnt2) {
                cnt2--;
            } else {
                res += s[i];
            }
        }
    }
    if (res[0] == '8') {
        cout << "YES" << endl;
    } else {
        cout << "NO"  << endl;
    }

    return 0;
}