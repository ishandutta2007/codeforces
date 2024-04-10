#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << -1 << '\n';
        } else {
            int t;
            vector<int> p(n + 10);
            if (n % 5 == 0 or n % 5 == 1) {
                p[0] = 1, p[1] = 4;
                p[2] = 2, p[3] = 5;
                p[4] = 3, p[5] = 6;
                t = 6;
            } else if (n % 5 == 2 or n % 5 == 3) {
                p[0] = 1, p[1] = 5;
                p[2] = 2, p[3] = 6;
                p[4] = 3, p[5] = 7;
                p[6] = 4, p[7] = 8;
                t = 8;
            } else {
                p[0] = 2, p[1] = 4;
                p[2] = 1, p[3] = 3;
                t = 4;
            }
            auto f = [&](int t) {
                p[t] = t + 3;
                p[t + 1] = t + 1; p[t + 2] = t + 4;
                p[t + 3] = t + 2; p[t + 4] = t + 5;
                return t + 5;
            };
            while (t < n) {
                t = f(t);
            }
            for (int i = 0; i < n; i++) {
                cout << p[i] << " \n"[i == n - 1];
            }
        }
    }
    return 0;
}