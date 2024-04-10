#include <iostream>

using namespace std;

long long solve(int a, int b, int c, int l) {
    long long res = 0;
    for(int i = 0; i <= l; i++) {
        int x = min(a + i - b - c, l - i);
        if(x < 0)
            continue;
        res += (long long)(x + 2) * (x + 1) / 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, l;
    cin >> a >> b >> c >> l;
    cout << (long long)(l + 3) * (l + 2) * (l + 1) / 6 -
        solve(a, b, c, l) - solve(b, c, a, l) - solve(c, a, b, l) << '\n';
    return 0;
}