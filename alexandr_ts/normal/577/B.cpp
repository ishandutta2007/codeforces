#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pr;

const ll N = 1e3 + 1;
const ll INF = 1e12;

int a[N * N], d[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];

    if (n > m) {
        cout << "YES";
        return 0;
    }

    d[0][0] = 1;
    fr(i, n)
        fr(j, m)
            if (d[i][j])
                d[i + 1][j]++, d[i + 1][(j + a[i]) % m]++;
    fr(i, n + 1)
        if (d[i][0] > 1) {
            cout << "YES";
            return 0;
        }
    cout << "NO";



}