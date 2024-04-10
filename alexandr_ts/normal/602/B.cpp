#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];

multiset <int> mn, mx;

int main() {
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;

    fr(i, n)
        cin >> a[i];
    int cur = 0, ans = 0;
    fr(i, n) {
        mn.insert(a[i]);
        mx.insert(-a[i]);
        while (cur < i - 1 && (-(*mx.begin()) - *mn.begin()) > 1) {
            mn.erase(mn.find(a[cur]));
            mx.erase(mx.find(-a[cur++]));
        }
        ans = max(ans, (int)mn.size());
        //cout << i << " " << cur << endl;
    }
    cout << ans;
}