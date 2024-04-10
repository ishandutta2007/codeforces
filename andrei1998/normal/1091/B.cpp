#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
    int N;
    cin >> N;

    lint s_x = 0, s_y = 0;
    for (int i = 1; i <= N; ++ i) {
        int x, y;
        cin >> x >> y;
        s_x += x;
        s_y += y;
    }
    for (int i = 1; i <= N; ++ i) {
        int x, y;
        cin >> x >> y;
        s_x += x;
        s_y += y;
    }

    cout << s_x / N << ' ' << s_y / N << endl;
    return 0;
}