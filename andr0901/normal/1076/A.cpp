#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s += 'a' - 1;
    //cout << s;
    forn (i, 0, n) {
        if (s[i] > s[i + 1]) {
            forn (j, 0, i)
                cout << s[j];
            forn (j, i + 1, n)
                cout << s[j];
            return 0;
        }
    }

    return 0;
}