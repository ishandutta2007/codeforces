#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const int N = 2e5 + 1;
const ll INF = 3e18;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld EPS = 1e-12;
const ll MOD = 1e9 + 7;

int a[N];

int main() {
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    int cur = n - 1;
    while (cur >= 0 && a[cur] == a[n - 1])
        cur--;
    int cnt = n - cur - 1;
    if (n - k + 1 > cnt)
        cout << -1;
    else
        cout << n - cnt;
}