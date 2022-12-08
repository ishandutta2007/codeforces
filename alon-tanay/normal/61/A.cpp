#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    cin >> b;
    int len = a.length();
    for(int i = 0; i < len; i ++) {
        cout << ((a[i]+b[i])%2);
    }
    return 0;
}