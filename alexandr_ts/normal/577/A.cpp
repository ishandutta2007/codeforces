#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pr;

const ll N = 3e5;
const ll MOD = 1e9 + 7;
const ll INF = 1e12;
const ll P = 11;

int main() {
    ld st = clock();
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin >> n >> x;
    int ans = 0;
    frab(i, 1, sqrt(x) + 1)
        if (x % i == 0)
            if (x / i <= n && x / i >= i)
                if (x / i == i)
                    ans++;
                else
                    ans += 2;
    cout << ans;
}