#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;
    int res = 0;
    while (a > 0) {
        res += a % 10;
        a /= 10;
    }   
    cout << (res % 9 ? res % 9 : 9) << endl;

    return 0;
}