#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void print(int a, int b) {
    cout << a << " " << b << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int i = 1;
    while (2 * i < n + 1) {
        forn (j, 1, m + 1) {
            print(i, j);
            print(n - i + 1, m - j + 1);
        }
        i++;
    }
    if (2 * i == n + 1) {
        for (int j = 1; 2 * j <= m + 1; j++) {
            print(i, j);
            if (2 * j != m + 1)
                print(n - i + 1, m - j + 1);
        }
    }
    return 0;
}