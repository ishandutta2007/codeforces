#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const string key = "heidi";

char s[MAXN + 1];

int main() {
    cin >> s;

    int idx = 0;
    for (int i = 0; s[i]; ++i) {
        if (idx < (int)key.size() and s[i] == key[idx]) {
            ++idx;
        }
    }

    if (idx == (int)key.size()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}