#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool fit(string s, string t) {
    if (s.length() != t.length())
        return 0;
    for (int i = 0; i < (int) s.length(); ++i)
        if (t[i] != '.' && t[i] != s[i])
            return false;
    return true;
}

string names[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    int n;
    string s;

    cin >> n >> s;
    for (int i = 0; i < 8; ++i)
        if (fit(names[i], s)) {
            cout << names[i] << "\n";
            return 0;
        }

    return 0;
}