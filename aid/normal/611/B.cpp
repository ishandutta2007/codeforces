#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    int ans = 0;
    for(long long x = 4; x <= 2 * b; x *= 2)
        for(long long y = x / 4; y >= 1; y /= 2)
            if(a <= x - 1 - y && x - 1 - y <= b)
                ans++;
    cout << ans << '\n';
    return 0;
}