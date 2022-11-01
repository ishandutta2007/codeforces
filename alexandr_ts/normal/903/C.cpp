#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 1e6 + 10;

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    map <int, int> m;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
    }
    int ans = 0;
    for (auto t: m)
        ans = max(ans, t.second);
    cout << ans;
}