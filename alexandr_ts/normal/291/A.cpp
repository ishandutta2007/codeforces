#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e12 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

ll a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    map <int, int> m;
    int t;
    fr(i, n) {
        cin >> t;
        if (t)
            m[t]++;
    }
    for (auto it = m.begin(); it != m.end(); it++)
        if (it->second > 2) {
            cout << -1;
            return 0;
        }
    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++)
        ans += (it->second) / 2;
    cout << ans;
}