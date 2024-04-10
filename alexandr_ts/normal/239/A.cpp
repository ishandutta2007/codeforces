#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = (int)a; i < (int)b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e2 + 10;
const int INF = 2e9;
const int ALPH = 300;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    ll x, y, k, n;
    cin >> x >> k >> n;
    y = (x + k - 1) / k * k - x;
    if (!y) y += k;
    vector <int> ans;
    while (y + x <= n)
        ans.pb(y), y += k;
    if (!ans.size())
        cout << -1;
    else fr(i, ans.size())
            cout << ans[i] << " ";
}