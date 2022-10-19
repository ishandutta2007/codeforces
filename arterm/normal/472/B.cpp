#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 2014

int n, k, a[M];

void read() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i -= k) {
        ans += 2 * a[i];
    }
    cout << ans << "\n";
}



int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    read();
    
    return 0;
}