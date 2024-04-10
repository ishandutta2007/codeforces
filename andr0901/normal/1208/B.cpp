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
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    int ans = n;
    set <int> was;
    forn (i, 0, n) {
        for (int j = n - 1; j >= i - 1; j--) {
            if (j == i - 1 || was.find(a[j]) != was.end()) {
                forn (k, j + 1, n) 
                    was.erase(a[k]);
                break;
            }
            else {
                was.insert(a[j]);
                ans = min(ans, j - i);
                //cout << i << " " << j << "\n";
            }
        }
        /*for (int j : was)
            cout << j << " ";
        cout << "\n\n";*/
        if (was.find(a[i]) != was.end())
            break;
        else {
            was.insert(a[i]);
            ans = min(ans, n - i - 1);
        }
    }
    cout << ans;
    return 0;
}