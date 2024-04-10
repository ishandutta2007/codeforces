#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, x, y, z;
    cin >> x >> y >> z >> a >> b >> c;
    if (a < x) {
        cout << "NO";
        return 0;
    }
    a -= x;
    int s = a + b;
    if (s < y) {
        cout << "NO";
        return 0;
    }
    s -= y;
    if (s + c < z) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}