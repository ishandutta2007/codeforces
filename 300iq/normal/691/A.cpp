#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    int cnt = 0;
    forn (i, n) {
        cin >> a[i];
        cnt += (a[i] == 0);
    }
    if (n == 1) {
        if (cnt == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (cnt == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}