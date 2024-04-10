#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
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

int change(int x) {
    return (x ^ 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <vector <int>> used(2,  vector <int> (n + 2));
    int bad = 0;
    while (q --> 0) {
        int x, y;
        cin >> x >> y, x--;
        if (!used[x][y]) {
            forn (i, -1, 2)
                if (used[change(x)][y + i])
                    bad++;
        } else {
            forn (i, -1, 2)
                if (used[change(x)][y + i])
                    bad--;
        }
        used[x][y] ^= 1;
        //cout << bad << ": ";
        if (bad == 0)
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
    }
    return 0;
}