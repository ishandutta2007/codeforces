#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    vector <int> ch;
    for (int i = 0; i < (int) a.size(); i++) {
        if (a[i] != b[i]) {
            ch.push_back(i);
        }
    }
    if (ch.size() & 1) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < (int) ch.size() / 2; i++) {
            a[ch[i]] = b[ch[i]];
        }
        cout << a << endl;
    }
}