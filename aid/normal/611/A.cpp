#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
    string s;
    cin >> x >> s >> s;
    if(s[0] == 'w') {
        if(x == 1)
            cout << 52 << '\n';
        else if(x == 2)
            cout << 52 << '\n';
        else if(x == 3)
            cout << 52 << '\n';
        else if(x == 4)
            cout << 52 << '\n';
        else if(x == 5)
            cout << 53 << '\n';
        else if(x == 6)
            cout << 53 << '\n';
        else
            cout << 52 << '\n';
    }
    else {
        if(x <= 29)
            cout << 12 << '\n';
        else if(x  == 30)
            cout << 11 << '\n';
        else if(x == 31)
            cout << 7 << '\n';
    }
    return 0;
}