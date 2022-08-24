#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'A') a++;
        else b++;
    }
    if (a == b) {
        cout << "Friendship\n";
        return 0;
    }
    cout << (a > b ? "Anton" : "Danik") << '\n';
}