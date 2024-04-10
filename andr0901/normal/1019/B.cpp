#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int n;

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int ans1;
    cin >> ans1;
    cout << "? " << i + 1 + n << endl;
    int ans2;
    cin >> ans2;
    return ans1 - ans2;
}

void no_ans() {
    cout << "! -1" << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n, n /= 2;
    if (n % 2)
        no_ans();
    if (ask(0) >= 0) {
        int l = 0, r = n;
        while (r - l > 1) {
            //cout << l << " " << r << endl;
            int m = l + r >> 1;
            if (ask(m) >= 0)
                l = m;
            else 
                r = m;
        }
        if (ask(l) == 0)
            return cout << "! " << l + 1 << endl, 0;
        else 
            no_ans();
    } else {
        int l = -1, r = n - 1;
        while (r - l > 1) {
            //cout << l << " " << r << endl;
            int m = l + r >> 1;
            if (ask(m) < 0)
                l = m;
            else 
                r = m;
        }
        if (ask(r) == 0)
            return cout << "! " << r + 1 << endl, 0;
        else 
            no_ans();
    }
    return 0;
}