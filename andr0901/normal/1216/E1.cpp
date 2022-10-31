#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string big_num = "1";
    int cur = 1;
    vector <int> pos = {0, 1};
    forn (i, 2, 4e4) {
        vector <char> to_push_back;
        int j = i;
        while (j) {
            to_push_back.push_back((char)((j % 10) + '0'));
            j /= 10;
        }
        while (!to_push_back.empty()) {
            big_num += to_push_back.back();
            to_push_back.pop_back();
        }
        pos.pb(pos.back() + sz(big_num));
        if (pos.back() > 1e9)
            break;
        //cout << i << " " << pos.back() << "\n";
    }
    //cout << "\n" << big_num << "\n";
    int q;
    cin >> q;
    while (q --> 0) {
        int k;
        cin >> k;
        int i = --lower_bound(all(pos), k) - pos.begin();
        cout << big_num[k - pos[i] - 1] << "\n";
        //cout << i << " " << k - pos[i] - 1 << "\n";
    }
    return 0;
}