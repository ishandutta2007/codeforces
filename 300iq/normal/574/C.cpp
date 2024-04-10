#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    set <int> res;
    forn (i, n) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
        }
        while (a[i] % 3 == 0) {
            a[i] /= 3;
        }
        res.insert(a[i]);
    }
    cout << (res.size() == 1 ? "Yes" : "No") << endl;
}