#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e3 + 10;
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N], b[N], c[N], d[N];


int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int ans1 = 0, cur = -1;
    fr(i, n) {
        do {
            cur++;
        }
        while (cur < n && t[cur] < s[i]);

        if (cur >= n)
            ans1++;
    }
    cout << ans1 << endl;

    int ans2 = 0;
    cur = -1;
    fr(i, n) {
        do {
            cur++;
        }
        while (cur < n && t[cur] <= s[i]);
        if (cur < n)
            ans2++;
    }
    cout << ans2;


}