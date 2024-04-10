#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int main() {
    string s;
    cin >> s;
    int st = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] != 'a') {
            st = i;
            break;
        }
    }
    if (st == 0 && s[st] == 'a') {
        s[(int) s.size() - 1] = 'z';
        cout << s << endl;
        return 0;
    }
    for (int i = st; i < (int) s.size(); i++) {
        if (s[i] == 'a') break;
        s[i]--;
    }
    cout << s << endl;
}