#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, d, h;
    cin >> n >> d >> h;
    if(d == 1) {
        if(h == 1 && n == 2)
            cout << 1 << ' ' << 2 << '\n';
        else
            cout << -1 << '\n';
        return 0;
    }
    if(h < (d + 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }
    if(h == d) {
        for(int i = 0; i < d; i++)
            cout << i + 1 << ' ' << i + 2 << '\n';
        for(int i = d + 1; i < n; i++)
            cout << d << ' ' << i + 1 << '\n';
        return 0;
    }
    for(int i = 0; i < h; i++)
        cout << i + 1 << ' ' << i + 2 << '\n';
    cout << 1 << ' ' << h + 2 << '\n';
    for(int i = h + 1; i < d; i++)
        cout << i + 1 << ' ' << i + 2 << '\n';
    for(int i = d + 1; i < n; i++)
        cout << 1 << ' ' << i + 1 << '\n';
    return 0;
}