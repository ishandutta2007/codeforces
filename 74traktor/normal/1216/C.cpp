#include <bits/stdc++.h>

using namespace std;

void f(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    if (x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2) {
        cout << "NO";
        exit(0);
    }
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    f(x1, y1, x2, y2, x3, y3, x4, y4);
    f(x1, y1, x2, y2, x5, y5, x6, y6);
    int X1 = max(x1, x3), X2 = min(x2, x4), Y1 = max(y1, y3), Y2 = min(y2, y4), X3 = max(x1, x5), X4 = min(x2, x6), Y3 = max(y1, y5), Y4 = min(y2, y6);
    if (X1 > X2 || Y1 > Y2 || X3 > X4 || Y3 > Y4) {
        cout << "YES" << '\n';
        return 0;
    }
    //cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << '\n';
    //cout << X3 << " " << Y3 << " " << X4 << " " << Y4 << '\n';
    if (X1 == x1 && X2 == x2 && X3 == x1 && X4 == x2) {
        pair < int, int > a1 = {Y1, Y2}, a2 = {Y3, Y4};
        if (a1 > a2) swap(a1, a2);
        int lef = a1.first, righ = a2.second;
        if (lef <= y1 && y2 <= righ && a1.second >= a2.first) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    if (Y1 == y1 && Y2 == y2 && Y3 == y1 && Y4 == y2) {
        pair < int, int > a1 = {X1, X2}, a2 = {X3, X4};
        if (a1 > a2) swap(a1, a2);
        int lef = a1.first, righ = a2.second;
        if (lef <= x1 && x2 <= righ && a1.second >= a2.first) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}