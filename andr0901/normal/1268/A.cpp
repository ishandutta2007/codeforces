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

void print(const string& s) {
    cout << s.size() << "\n";
    forn (i, 0, sz(s))
        cout << static_cast <char> (s[i] + '0');
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    forn (i, 0, n)
        a[i] -= '0';
    string b;
    forn (i, 0, k)
        b += a[i];
    string c;
    forn (i, 0, n)
        c += a[i % k];
    if (c >= a)
        print(c);
    else {
        reverse(all(b));
        int carry = 1;
        forn (i, 0, k) {
            b[i] += carry;
            carry = b[i] / 10;
            b[i] %= 10;
        }
        if (carry)
            b += carry;
        reverse(all(b));
        //print(b);
        string ans;
        forn (i, 0, n)
            ans += b[i % k];
        print(ans);
    }
    return 0;
}