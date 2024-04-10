#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    cout << 2ll * *max_element(a, a + n) - accumulate(a, a + n, 0ll) + 1;
}