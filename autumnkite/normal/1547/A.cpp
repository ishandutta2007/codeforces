#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        int xA, yA, xB, yB, xF, yF;
        std::cin >> xA >> yA >> xB >> yB >> xF >> yF;
        int ans = abs(xA - xB) + abs(yA - yB);
        int sum = abs(xA - xF) + abs(yA - yF) + abs(xB - xF) + abs(yB - yF);
        if (ans == sum && (xA == xB || yA == yB)) {
            std::cout << ans + 2 << "\n";
        } else {
            std::cout << ans << "\n";
        }
    }
}