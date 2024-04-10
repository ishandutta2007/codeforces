#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

vector <pii> sol;

int main() {
    ll X;
    scanf("%I64d", &X);
    X *= 6;
    for (ll n = 1; n < 2000000; n++) {
        ll tmp = n * (n + 1);
        if (X % tmp) continue;
        ll m = X / tmp + n - 1;
        if (m % 3) continue;
        m /= 3;
        if (n > m) continue;
        sol.push_back(pii(n, m));
        if (n < m) sol.push_back(pii(m, n));
    }
    
    sort(sol.begin(), sol.end());
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%I64d %I64d\n", sol[i].first, sol[i].second);
    return 0;
}