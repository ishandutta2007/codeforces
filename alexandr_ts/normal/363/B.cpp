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
const int INF = 2e9 + 1;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    ll sum = accumulate(a, a + k, 0);
    ll ans = sum;
    ll pos = 0;
    frab(i, k, n) {
        sum -= a[i - k];
        sum += a[i];
        if (ans > sum) {
            ans = sum;
            pos = i - k + 1;
        }
    }
    cout << pos + 1;

}