#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

ll a[100100];
pair<ll, int> ans[100100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        ans[i].sc = i;
    }
    vector<bool> used(n, false);
    for (int j = 60 - 1; j >= 0; --j) {
        vector<pair<ll, int> > b;
        forn (i, n) {
            if (used[i] && (a[i] & (1ll << j))) {
                b.pb(ans[i]);
            }
        }
        sort(b.begin(), b.end());
//        cerr << j << " " << b.size() << endl;
        int cur = 0;
        ll mx = 0;
        forn (i, n) {
            if (!used[i] && (a[i] & (1ll << j))) {
                used[i] = true;
                if (cur < int(b.size())) {
                    ans[i].fs = ans[b[cur].sc].fs - (1ll << j);
                    mx = ans[b[cur].sc].fs;
                } else if (cur  == int(b.size())) {
                    ans[i].fs = mx + (1ll << j);
                } else {
                    cout << "No\n";
                    return 0;
                }
                cur++;
            }
        }
    }
    cout << "Yes\n";
    sort(ans, ans + n);
    forn (i, n) {
        cout << a[ans[i].sc] << " ";
    }/*
    ll x = 0;
    cerr << endl;
    forn (i, n) {
        x ^= a[ans[i].sc];
        cerr << x << " ";
    }*/
    return 0;
}