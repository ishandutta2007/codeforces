#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector <int> f(26);
    for (int i = 0; i < 26; i++) {
        cin >> f[i];
    }
    int head = s.length();
    int cur = 0;
    for (int i = 0; i < head; i++) {
        cur += (i + 1) * f[s[i] - 'a'];
    }
    sort (f.begin(), f.end());
    while (k--) {
        head++;
        cur += head * f[25];
    }
    cout << cur << endl;
}