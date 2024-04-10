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

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    int a, b;
    cin >> n >> k >> a >> b;
    int maxx = 0;
    int minn = 1e17;
    for (int i = 0; i < n; i++) {
        int pos1, pos2, x, g;
        pos1 = a;
        pos2 = k * i + b;
            g = gcd(abs(pos2 - pos1), n * k);
            x = n * k / g;
            maxx = max(maxx, x);
            minn = min(minn, x);
        pos1 = a;
        pos2 = k * (i + 1) - b;
            g = gcd(abs(pos2 - pos1), n * k);
            x = n * k / g;
            maxx = max(maxx, x);
            minn = min(minn, x);

        pos1 = k - a;
        pos2 = k * i + b;
            g = gcd(abs(pos2 - pos1), n * k);
            x = n * k / g;
            maxx = max(maxx, x);
            minn = min(minn, x);

        pos1 = k - a;
        pos2 = k * (i + 1) - b;
            g = gcd(abs(pos2 - pos1), n * k);
            x = n * k / g;
            maxx = max(maxx, x);
            minn = min(minn, x);
    }
    cout << minn << " " << maxx << endl;


    return 0;
}