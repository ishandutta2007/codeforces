#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 400;
int a[maxn];

int main() {
    int n;
    cin >> n;
    int l = n / 7;
    l *= 7;
    int r = n % 7;
    while (r % 4 != 0){
        if (l < 0){
            cout << -1 << endl;
            return 0;
        }
        l -= 7;
        r += 7;
        if (l < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < r / 4; i++)
        cout << '4';
    for (int i = 0; i < l / 7; i++)
        cout << '7';
}