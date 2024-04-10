#include <bits/stdc++.h>

using namespace std;

bool check_in(int t1, int t2, int a, int b, int c) {
    t1 *= 3600;
    t2 *= 3600;
    a *= 3600;
    b *= 60;
    return (t1 <= a + b + c && a + b + c <= t2) ||
           (t1 <= 12 * (b + c) && 12 * (b + c) <= t2) ||
           (t1 <= 12 * 60 * c && 12 * 60 * c <= t2);
}

bool check_out(int t1, int t2, int a, int b, int c) {
    t1 *= 3600;
    t2 *= 3600;
    a *= 3600;
    b *= 60;
    return !(t1 <= a + b + c && a + b + c <= t2) ||
           !(t1 <= 12 * (b + c) && 12 * (b + c) <= t2) ||
           !(t1 <= 12 * 60 * c && 12 * 60 * c <= t2);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    tie(t1, t2) = minmax({t1, t2});
    //cout << check_in(t1, t2, h, m, s) << ' ' << check_out(t1, t2, h, m, s) << endl;
    //cout << 60 * t1 << ' ' << 12 * b << ' ' << 60 * t2 << endl;
    if(check_in(t1, t2, h, m, s) && check_out(t1, t2, h, m, s)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    
}