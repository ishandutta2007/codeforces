#include <iostream>
#include <string>

using namespace std;

void getMin(int l, int r, string &s) {
    if((r - l) & 1)
        return;
    int m = (l + r) / 2;
    getMin(l, m, s);
    getMin(m, r, s);
    bool b = false;
    for(int i = 0; i < m - l; i++)
        if(s[l + i] != s[m + i]) {
            if(s[l + i] > s[m + i])
                b = true;
            break;
        }
    if(b)
        for(int i = 0; i < m - l; i++)
            swap(s[l + i], s[m + i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    getMin(0, s.length(), s);
    getMin(0, t.length(), t);
    cout << (s == t? "YES" : "NO") << '\n';
    return 0;
}