#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ios_base::sync_with_stdio(0);
    vector <int> s;
    int n, x;
    scanf("%d", &n);
    forn (i, n) {
        scanf("%d", &x);
        s.pb(x);
    }
    sort(all(s));
    int l = 0, r = n / 2;
    int cnt = n;
    while (l < n / 2 && r < n) {
        if (s[l] * 2 <= s[r]) {
            l++;
            cnt--;
        }
        r++;
    }
    cout << cnt << endl;

}