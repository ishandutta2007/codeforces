#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 5e3 + 2;
const ld EPS = 1e-8;

ll d[N][N], a[N];
ll pref[N];

ll sum(ll l, ll r) {
    return pref[r] - pref[l - 1];
    //return accumulate(a + l, a + r + 1, 0ll);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int ans = INF, pos1;
    fr(i, n)
        if (abs(a[i] - a[(i + 1) % n]) < ans)
            ans = abs(a[i] - a[(i + 1) % n]), pos1 = i;
    cout << pos1 + 1 << " " << (pos1 + 1) % n + 1;
}