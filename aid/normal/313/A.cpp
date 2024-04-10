#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n > 0)
        cout << n << '\n';
    else
        if(-n % 10 > -n % 100 / 10)
            cout << n / 10 << '\n';
        else
            cout << (n / 100) * 10 + n % 10 << '\n';
}