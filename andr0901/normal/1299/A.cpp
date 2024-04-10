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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    //cout << (1 << 30);
    vector <int> a(n);
    vector <int> bits(30);
    forn (i, 0, n) {
        cin >> a[i];
        forn (j, 0, 30)
            if ((a[i] >> j) & 1)
                bits[j]++;
    }
    vector <pii> cnt(n);
    forn (i, 0, n) {
        cnt[i].sc = i;
        forn (j, 0, 30)
            if (((a[i] >> j) & 1) && bits[j] == 1)
                cnt[i].fs += (1 << j);
    }
    sort(rall(cnt));
    forn (i, 0, n) {
        cout << a[cnt[i].sc] << " ";
        //cout << cnt[i].fs << " " << cnt[i].sc << "\n";
    }
    return 0;
}