#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << "? ";
    for(int i = 0; i < 100; i ++) {
        cout << i << " ";
    }
    cout << endl;

    int x;
    cin >> x;
    x /= 128;

    cout << "? ";
    for(ll i = 1; i <= 100; i ++) {
        cout << (128*i) << " ";
    }
    cout << endl;

    int y;
    cin >> y;
    y %= 128;
    cout << "! " << (x*128 + y) << endl;
    return 0;
}