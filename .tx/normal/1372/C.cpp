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
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        std::vector<int> elems(n);

        int fixed = 0;
        for (int j = 0; j < n; j++) {
            cin >> elems[j];
            elems[j]--;
            if (elems[j] == j) fixed++;
        }

        if (fixed == 0) {
            std::cout << 1 << "\n";
        } else if (fixed == n) {
            std::cout << 0 << "\n";
        } else {
            int pref_fixed = 0;
            for (int j = 0; j < n; j++) {
                if (elems[j] == j) pref_fixed++;
                else break;
            }

            int suf_fixed = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (elems[j] == j) suf_fixed++;
                else break;
            }

            if (pref_fixed + suf_fixed == fixed) {
                std::cout << 1 << "\n";
            } else {
                std::cout << 2 << "\n";
            }
        }
    }


    return 0;
}