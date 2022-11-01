#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1003;
const int N = 1e6 + 10;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    vector <int> b;
    fr(i, n)
        if (!a[i])
            b.pb(i);
    if (!b.size()) {
        cout << n;
        return 0;
    }

    int ans = n - (int)b.size();
    fr(i1, b.size()) {
        int i = b[i1];
        int c1 = 0;
        fr(j, i)
            if (!a[j])
                c1++;
        frab(j, i + 1, n)
            if (a[j])
                c1++;
        ans = max(ans, c1 + 1);
    }
    cout << ans;
}