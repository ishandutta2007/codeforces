#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            std::cout << n / 2 << " " << n / 2 << "\n";
            continue;
        }
        bool flag = false;
        for (int d = 3; d * d <= n; d += 2) {
            if (n % d == 0) {
                d = n / d;
                std::cout << d << " " << n - d << "\n";
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << 1 << " " << n - 1 << "\n";
        }
    }



    return 0;
}