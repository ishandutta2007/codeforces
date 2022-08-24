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
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    set <int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    sort(all(a));
    if (s.size() == 1) {
        puts("YES");
    } else if (s.size() == 2) {
        puts("YES");
    } else if (s.size() == 3) {
        bool gg = 0;
        for (auto c : s) {
            set <int> f;
            for (int i = 0; i < n; i++) {
                if (a[i] < c) {
                    f.insert(a[i]);
                }
            }
            set <int> g;
            for (int i = 0; i < n; i++) {
                if (a[i] > c) {
                    g.insert(a[i]);
                }
            }
            if (f.size() != 1 || g.size() != 1) {
                continue;
            } 
            int p = *s.begin();
            int v = *g.begin();
            if (abs(p - c) == abs(v - c)) {
                gg |= 1;
            }
        }
        if (gg) {
            puts("YES");
        } else {
            puts("NO");
        }
    } else {
        puts("NO");
    }
}