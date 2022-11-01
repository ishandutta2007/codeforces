#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int M = 1e3 + 2;
const ll INF = 2e9 + 7;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-10;

int a[N];
bool p[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (ll i = 2; i <= n + 2; i++)
        if (!p[i])
            for (ll j = i * i; j <= n + 2; j += i)
                p[j] = true;
    if (n <= 2)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    frab(i, 2, n + 2)
        if (p[i])
            cout << 2 << " ";
        else
            cout << 1 << " ";
}