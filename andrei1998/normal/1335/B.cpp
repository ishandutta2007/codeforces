#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string str;
        for (int i = 0; i < n; ++i) {
            str += 'a' + (i % b);
        }
        cout << str << endl;
    }
    return 0;
}