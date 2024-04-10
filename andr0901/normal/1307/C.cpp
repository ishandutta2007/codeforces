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
    string s;
    cin >> s;
    long long ans = 0;
    map <pair <char, char>, long long> b;
    map <char, long long> cnt;
    forn (i, 0, sz(s)) {
        for (char c = 'a'; c <= 'z'; ++c) {
            b[{c, s[i]}] += cnt[c];
            ans = max(ans, b[{c, s[i]}]);
        }
        cnt[s[i]]++;
        ans = max(ans, cnt[s[i]]);
    }
    cout << ans;
    return 0;
}