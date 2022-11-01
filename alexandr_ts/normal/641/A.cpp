#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N];

bool used[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    fr(i, n)
        cin >> a[i];
    int cur = 0;
    fr(i, n + 1) {
        used[cur] = true;
        if (s[cur] == '>')
            cur += a[cur];
        else
            cur -= a[cur];
        if (cur < 0 || cur >= n) {
            cout << "FINITE";
            return 0;
        }
        if (used[cur]) {
            cout << "INFINITE";
            return 0;
        }
    }
}