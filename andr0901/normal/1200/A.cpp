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

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <bool> busy(10);
    forn (i, 0, n) {
        char c;
        cin >> c;
        if (c == 'L') {
            forn (j, 0, 10) {
                if (!busy[j]) {
                    busy[j] = 1;
                    break;
                }
            }
        } else if (c == 'R') {
            forn (j, 10, 0) {
                if (!busy[j]) {
                    busy[j] = 1;
                    break;
                }
            }
        } else {
            busy[(int)(c - '0')] = 0;
        }
       /* forn (j, 0, 10) 
        cout << (busy[j]);
        cout << "\n";*/
    }
    forn (i, 0, 10) 
        cout << (busy[i]);
    return 0;
}