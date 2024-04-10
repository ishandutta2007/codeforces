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
#define x first
#define y second

int nxt() {
    int x;
    cin >> x;
    return x;
}

vector <pii> a;

bool is_good(int x, int y, int len, int i) {
    return a[i].x == x && y <= a[i].y && a[i].y <= y + len ||
           a[i].x == x + len && y <= a[i].y && a[i].y <= y + len || 
           a[i].y == y && x <= a[i].x && a[i].x <= x + len ||
           a[i].y == y + len && x <= a[i].x && a[i].x <= x + len;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n = 4 * nxt() + 1; 
    a = vector <pii> (n);
    forn (i, 0, n)
        a[i] = {nxt(), nxt()};
    int N = 50;
    forn (x, 0, N + 1) {
        forn (y, 0, N + 1) {
            forn (len, 1, N + 1) {
                if (x + len > N || y + len > N)
                    break;
                int cnt = 0;
                forn (i, 0, n)  
                    cnt += is_good(x, y, len, i);
                if (cnt == n - 1) {
                    forn (i, 0, n) 
                        if (!is_good(x, y, len, i))
                            return cout << a[i].x << " " << a[i].y << "\n", 0;
                }
            }
        }
    }
    return 0;
}