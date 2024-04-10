#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int h = ceil(1.0 * n / 20), l = ceil(1.0 * n / ceil(1.0 * n / 20));
    cout << h << " " << l << "\n";
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        if (n % h == 0) {
            for (int j = 0; j < l; j++)
                cout << s[cnt++];
        } else {
            for (int j = 0; j < l - 1; j++)
                cout << s[cnt++];
            if (i < h - n % h)
                cout << "*";
            else
                cout << s[cnt++];
        }
        cout << "\n";
    }
    return 0;
}