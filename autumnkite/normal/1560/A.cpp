#include <bits/stdc++.h>

const int N = 1000;

int a[N];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 0, v = 1; i < N; ++i) {
        while (!(v % 3 != 0 && v % 10 != 3)) {
            ++v;
        }
        a[i] = v;
        ++v;
    }
    
    int T;
    std::cin >> T;
    while (T--) {
        int k;
        std::cin >> k;
        --k;
        std::cout << a[k] << "\n";
    }
}