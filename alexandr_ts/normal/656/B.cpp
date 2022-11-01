#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 3e2 + 10;
const ll M = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

int m[N], r[N];

int main() {
    //freopen("a.in", "r", stdin);
    //srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fr(i, n)
        cin >> m[i];
    fr(i, n)
    cin>> r[i];
    ll cnt = 0;
    fr(i, 1000000) {
        bool fnd = false;
        fr(j, n)
            if (i % m[j] == r[j])
                fnd = true;
        //cout << i << " " << fnd << endl;
        cnt += fnd;
    }
    cout << fixed << setprecision(12) << (ld)cnt / (ld)(1000000);
}