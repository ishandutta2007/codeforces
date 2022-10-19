#include <bits/stdc++.h>

using namespace std;

string s, t;

void run(int l, int len, string &s) {
    if (len % 2 == 1)
        return;
    run(l, len / 2, s);
    run(l + len / 2, len / 2, s);
    if (s.substr(l, len / 2) >= s.substr(l + len / 2, len / 2))
        for (int i = 0; i < len / 2; ++i)
            swap(s[l + i], s[l + i + len / 2]);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> s >> t;

    int n = s.length();
    run(0, n, s);
    run(0, n, t);
    
    if (s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}