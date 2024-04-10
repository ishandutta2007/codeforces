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
    ll n, k;
    cin >> n >> k;
    ll l = 0, r = INF;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        ll sum = 0;
        ll cur = 1;
        while (m >= cur) {
            sum += m / cur;
            cur *= k;
        }
        if (sum >= n)
            r = m;
        else
            l = m;
    }
    cout << r;
}