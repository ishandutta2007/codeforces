#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, len;
    string w;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> w;
        len = w.length();
        cout << ((len > 10) ? (w[0] + to_string(len - 2) + w[len-1]) : w) << endl;
    }
    return 0;
}