#include <bits/stdc++.h>

using namespace std;


int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector <int> r(n);
    vector < pair <int, int> > r1(n);
    for ( int i = 0; i < n; i++) {
        cin >> r[i];
        r1[i].first = r[i];
        r1[i].second = i;
    }

    sort(r1.begin(), r1.end());
    vector <int> m(n);
    m[r1[n - 1].second] = 0;
    for ( int i = n - 2; i >= 0; i--) {
        if ( r1[i].first == r1[i + 1].first) {
            m[r1[i].second] = m[r1[i + 1].second] + 1;
        }
        else {
            m[r1[i].second] = (n - 1 - i);
        }
    }

    for ( int i = 1; i < n; i++) {
        if ( r1[i].first == r1[i - 1].first) {
            m[r1[i].second] = max(m[r1[i - 1].second], m[r1[i].second]);
            m[r1[i - 1].second] = m[r1[i].second];
        }
    }

    for ( int i = 0; i < n; i++) {
        m[i] = (n - 1 - m[i]);
    }

    for ( int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        if ( r[x - 1] > r[y - 1]) {
            m[x - 1]--;
        }
        if ( r[x - 1] < r[y - 1]) {
            m[y - 1]--;
        }
    }

    for ( auto &c : m) {
        cout << c << " ";
    }











    return 0;
}