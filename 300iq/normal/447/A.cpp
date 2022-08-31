#include <bits/stdc++.h>

using namespace std;

int main() {
    int p, n, k;
    cin >> p >> n;
    map <int, int> h;
    for (int i = 0; i < n; i++) {
       cin >> k;
       if (h[k % p] == 1) return 0 * printf("%d", i + 1);
       h[k % p] = 1;
    }
    puts("-1");
}