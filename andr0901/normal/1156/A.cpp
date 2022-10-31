#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void infinite() {
    cout << "Infinite";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    int prev;
    cin >> prev;
    bool used = 0;
    forn (i, 1, n) {
        int a;
        cin >> a;
        if (a == 1) {
            if (prev == 1)
                infinite();
            if (prev == 2)
                ans += 3, used = 0;
            if (prev == 3) {
                ans += 4;
                if (used)
                    ans--;
                used = 1;
            }
        }
        if (a == 2) {
            if (prev == 2 || prev == 3)
                infinite();
            if (prev == 1) {
                ans += 3;
                if (used)
                    ans--;
                used = 1;
            }
        }
        if (a == 3) {
            if (prev == 2 || prev == 3)
                infinite();
            if (prev == 1) 
                ans += 4, used = 0;
        }
        prev = a;
    }
    cout << "Finite\n";
    cout << ans;
    return 0;
}