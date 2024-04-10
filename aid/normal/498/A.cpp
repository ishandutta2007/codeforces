#include <iostream>

using namespace std;

int sgn(long long x) {
    return (x > 0) - (x < 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    long long x0, y0, x1, y1;
    int n;
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if(sgn(a * x0 + b * y0 + c) * sgn(a * x1 + b * y1 + c) < 0)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}