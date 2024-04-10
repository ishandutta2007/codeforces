#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int n, p;
string s;


char nxt(char x, char y) {
    int t = 0;
    if (x == 'a' || y == 'a') {
        ++t;
        if (x == 'b' || y == 'b')
            ++t;
    }
    if (t >= p)
        return 0;
    return 'a' + t;
}

char nxt(char x) {
    int t = 0;
    if (x == 'a')
        t = 1;
    if (t >= p)
        return 0;
    return 'a' + t;
}

bool possible(int k) {
    while (k < (int) s.length()) {
        s[k] = k == 1 ? nxt(s[k - 1]) : nxt(s[k - 1], s[k - 2]);
        if (s[k] == 0)
            return false;
        ++k;
    }
    return true;
}

void kill() {
    cin >> n >> p;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; --i) {
        s[i] = s[i] + 1;
        for (;s[i] != 'a' + p; s[i] = s[i] + 1)
            if (possible(i + 1)) {
                bool ans = true;
                for (int j = 1; j <= 2 && i - j >= 0; ++j)
                    if (s[i - j] == s[i])
                        ans = false;
                if (ans) {
                    cout << s << "\n";
                    return;
                }
            }
    }
    cout << "NO\n";
    return;
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    kill();
    return 0;
}