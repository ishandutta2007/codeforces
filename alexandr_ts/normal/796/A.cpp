#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 1e5+1;
const int INF = 1e9;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    fr(i, n)
        cin >> a[i];
    int ans = INF;
    fr(i, n)
        if (a[i] && a[i] <= k)
            ans = min(ans, abs(i - m + 1));
    cout << ans * 10;
}