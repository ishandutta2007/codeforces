#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 3e5 + 20;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector <int> b(n);
    fr(i, n)
        b[i] = i;
    fr(i, k)
        cin >> a[i];
    int cur = 0;
    fr(i, k) {
        cur = (cur + a[i]) % (int)b.size();
        cout << b[cur] + 1 << " ";
        b.erase(b.begin() + cur, b.begin() + cur + 1);
    }
}