#include <bits/stdc++.h>

using namespace std;

string s;
int n, x, y;

bool good(int m) {
    int nowx = 0, nowy = 0;
    for (int i = m; i < n; i++) {
        if (s[i] == 'U') {
            nowy++;
        }
        if (s[i] == 'R') {
            nowx++;
        }
        if (s[i] == 'D') {
            nowy--;
        }
        if (s[i] == 'L') {
            nowx--;
        }
    }
    for (int i = 0; i + m - 1 < n; i++) {
        if (abs(x - nowx) + abs(y - nowy) <= m) {
            return true;
        }
        if (s[i] == 'U') {
            nowy++;
        }
        if (s[i] == 'R') {
            nowx++;
        }
        if (s[i] == 'D') {
            nowy--;
        }
        if (s[i] == 'L') {
            nowx--;
        }
        if (i + m == n) {
            break;
        }
        if (s[i + m] == 'U') {
            nowy--;
        }
        if (s[i + m] == 'R') {
            nowx--;
        }
        if (s[i + m] == 'D') {
            nowy++;
        }
        if (s[i + m] == 'L') {
            nowx++;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    cin >> s;
    cin >> x >> y;
    if (abs(x) + abs(y) > n || ((abs(x) + abs(y)) % 2 == 1 && n % 2 == 0) || ((abs(x) + abs(y)) % 2 == 0 && n % 2 == 1)) {
        cout << -1;
        return 0;
    }
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (good(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r;
    return 0;
}