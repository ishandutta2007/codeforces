#include<bits/stdc++.h>

using namespace std;

bool exists[64][64];

int main() {
    for (int i = 0; i < 64; ++i) for (int j = 0; j < 64; ++j) exists[i][j] = false;
    int n;
    cin >> n;
    long long base = 0;
    for (int i = 0; i < n; ++i) {
        long long v;
        cin >> v;
        int p2 = 0, p3 = 0;
        while (v % 2 == 0) v /= 2, ++p2;
        while (v % 3 == 0) v /= 3, ++p3;
        base = v;
        exists[p2][p3] = true;
    }
    for (int i = 0; i < 64; ++i) {
        for (int j = 63; j >= 0; --j) {
            if (exists[i][j]) {
                int cnt = 1;
                long long v = base;
                for (int k = 0; k < i; ++k) v *= 2;
                for (int k = 0; k < j; ++k) v *= 3;
                cout << v;
                while (cnt < n) {
                    if (exists[i + 1][j]) {
                        v *= 2, ++i;
                    } else {
                        v /= 3, --j;
                    }
                    cout << ' ' << v;
                    ++cnt;
                }
                cout << '\n';
                break;
            }
        }
    }

    return 0;
}