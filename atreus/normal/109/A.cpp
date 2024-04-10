#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = n - (n % 7);
    int b = n % 7;
    while (b % 4 != 0){
        a -= 7;
        b += 7;
        if (a < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < b / 4; i++)
        cout << '4';
    for (int i = 0; i < a / 7; i++)
        cout << '7';
}