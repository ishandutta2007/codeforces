#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 10005;


int main() {
    int n, m;
    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; ++ i) {
        cin >> str;
    }
    str = "." + str + ".";
    int cnt = 0;
    for (int i = 1; i <= m + 1; i += 1) {
        if (str[i] == '.' && str[i - 1] == 'B') {
            ++ cnt;
        }
    }
    cout << cnt << "\n";
    return 0;
}