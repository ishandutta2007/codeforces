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
#define int long long

int nxt() {
    int x;
    cin >> x;
    return x;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n = nxt(), m = nxt(), k = nxt();
    set <int> a;
    forn (i, 0, m)  
        a.insert(nxt());
    int i = 0, last = k;
    while (!a.empty()) {
        last = max(0LL, (*a.begin() - last + k - 1) / k) * k + last;
        int to_add = 0;
        //cout << last << " ";
        while (!a.empty() && *a.begin() <= last) {
            a.erase(a.begin());
            to_add++;
        }
        last += to_add;
        i++;
        //cout << last << " " << i << "\n";
    }
    cout << i;
    return 0;
}