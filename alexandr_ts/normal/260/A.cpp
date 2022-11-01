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
const ll N = 1e6 + 2;
const ld EPS = 1e-8;

ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int a, b, n;
    cin >> a >> b >> n;
    int ch = -1;
    fr(i, 10) {
        if ((a * 10 + i) % b == 0)
            ch = i;
    }
    if (ch == -1) {
        cout << -1;
    }
    else {
        cout << a << ch;
        fr(i, n - 1)
            cout << 0;
    }
}