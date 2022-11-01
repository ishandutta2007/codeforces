#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

set< string > ans;
string a, b;

bool good(string s, string a) {
    int pre = 0, suf = 0;

    for (int i = 0; i < a.size() && s[i] == a[i]; i++) {
        pre++;
    }

    for (int i = a.size() - 1; i >= 0 && s[i + 1] == a[i]; i--) {
        suf++;
    }

    return pre + suf >= a.size();
}

void try_add(string s, bool rev = false) {
    if (good(s, a) && good(s, b)) {
        if (rev) {
            reverse(s.begin(), s.end());
        }

        ans.insert(s);
    }
}

int main() {
    int n;

    cin >> n;

    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            try_add(a.substr(0, i) + string(1, b[i]) + a.substr(i));
            try_add(b.substr(0, i) + string(1, a[i]) + b.substr(i));
            break;
        }
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            try_add(a.substr(0, i) + string(1, b[i]) + a.substr(i), true);
            try_add(b.substr(0, i) + string(1, a[i]) + b.substr(i), true);
            break;
        }
    }

    cout << ans.size() << endl;

    return 0;
}