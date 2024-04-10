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
const ll N = 1e6 + 1;
const ld EPS = 1e-8;

int f[N], b[N], a[N];

bool cmp(pr a, pr b) {
    return a.first < b.first || a.first == b.first && a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    ll x, n;
    cin >> n;
    fr(i, n) {
        cin >> x;
        //ll mn = (1 << ((int)log2(x))
        cout << x * (x + 1) / 2 - 2ll * (1ll << ((ll)(log2(x) + 1ll))) + 2ll << endl;
    }
}