#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    if (a.size() < b.size()) a = string(b.size() - a.size(), '0') + a;
    if (a.size() > b.size()) b = string(a.size() - b.size(), '0') + b;
    if (a < b) cout << '<';
    else if (a > b) cout << '>';
    else cout << '=';
    cout << endl;
    return 0;
}