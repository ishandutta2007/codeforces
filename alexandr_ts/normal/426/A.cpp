#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    if (accumulate(a, a + n - 1, 0) > k)
        cout << "NO";
    else
        cout << "YES";
}