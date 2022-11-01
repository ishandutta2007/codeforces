#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ll INF = 2e9;
const ld EPS = 1e-8;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    map <ll, ll> m;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
    }
    ll sm = accumulate(a, a + n, 0ll);
    cout << max(*max_element(a, a + n), (sm + n - 2) / (n - 1));
}