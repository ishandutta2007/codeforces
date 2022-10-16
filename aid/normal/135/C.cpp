#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = s.length(), c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++) {
        c0 += (s[i] == '0');
        c1 += (s[i] == '1');
    }
    int x = n - c0 - c1;
    if(c0 + x > c1)
        cout << "00\n";
    if(c0 <= n / 2 && c0 + x >= n / 2) {
        if(s[n - 1] == '1')
            cout << "01\n";
        else if(s[n - 1] == '0')
            cout << "10\n";
        else {
            if(c0 + x > n / 2)
                cout << "01\n";
            if(c0 < n / 2)
                cout << "10\n";
        }
    }
    if(c1 + x > c0 + 1)
        cout << "11\n";
    return 0;
}