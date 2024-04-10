#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ll INF = 2e9 + 1;

ll a1[5], b1[5];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    frab(i, 1, n + 1)
        a1[i % 5]++;
    frab(i, 1, m + 1)
        b1[i % 5]++;
    ll ans = 0;
    fr(i, 5)
        ans += a1[i] * b1[(5 - i) % 5];
    cout << ans;
}