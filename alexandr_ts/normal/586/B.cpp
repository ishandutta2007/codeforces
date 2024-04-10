#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int a[N], b[N], c[N];

int main() {
    //freopen("birthday.in", "r", stdin);
    //freopen("birthday.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fr(i, n - 1) cin >> a[i];
    fr(i, n - 1) cin >> b[i];
    fr(i, n) cin >> c[i];
    vector <int> ans;
    fr(i, n) {
        int x = 0;
        fr(j, i) x += a[j];
        for (int j = n - 2; j >= i; j--)
            x += b[j];
        x += c[i];
        ans.pb(x);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] + ans[1];
}