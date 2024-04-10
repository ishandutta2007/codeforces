#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 * 1000 + 5;
string s;
int x[MAXN], y[MAXN], z[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    if(s[0] == 'x')
        x[0]++;
    else if(s[0] == 'y')
        y[0]++;
    else
        z[0]++;
    for(size_t i = 1; i < s.length(); i++) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        z[i] = z[i - 1];
        if(s[i] == 'x')
            x[i]++;
        else if(s[i] == 'y')
            y[i]++;
        else
            z[i]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int xn = x[r] - (l? x[l - 1] : 0),
            yn = y[r] - (l? y[l - 1] : 0),
            zn = z[r] - (l? z[l - 1] : 0);
        if(r - l + 1 >= 3 && max(xn, max(yn, zn)) > min(xn, min(yn, zn)) + 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}