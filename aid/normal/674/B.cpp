#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    if(k <= n || n == 4) {
        cout << -1 << '\n';
        return 0;
    }
    int e = 0;
    while(e == a || e == b || e == c || e == d)
        e++;
    int f;
    if(n == 5)
        f = e;
    else {
        f = 0;
        while(f == a || f == b || f == c || f == d || f == e)
            f++;
    }
    cout << a + 1 << ' ' << c + 1 << ' ' << e + 1 << ' ';
    for(int i = 0; i < n; i++)
        if(i != a && i != b && i != c && i != d && i != e && i != f)
            cout << i + 1 << ' ';
    if(n != 5)
        cout << f + 1 << ' ';
    cout << d + 1 << ' ' << b + 1 << '\n';
    cout << c + 1 << ' ' << a + 1 << ' ' << e + 1 << ' ';
    for(int i = 0; i < n; i++)
        if(i != a && i != b && i != c && i != d && i != e && i != f)
            cout << i + 1 << ' ';
    if(n != 5)
        cout << f + 1 << ' ';
    cout << b + 1 << ' ' << d + 1 << '\n';
    return 0;
}