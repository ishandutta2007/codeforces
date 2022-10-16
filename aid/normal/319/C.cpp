#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
const long double EPS = 1e-9;
int a[MAXN], b[MAXN], id[MAXN], k, p;
long long dp[MAXN];

long long getY(int l, int x) {
    return dp[l] + (long long)b[l] * x;
}

long long get(int x) {
    p = min(p, k);
    while(p < k - 1 && getY(id[p + 1], x) < getY(id[p], x))
        p++;
    return getY(id[p], x);
}

bool bad(int l0, int l1, int l2) {
    return (long double)(dp[l1] - dp[l0]) / (b[l0] - b[l1]) >=
        (long double)(dp[l2] - dp[l1]) / (b[l1] - b[l2]) - EPS;
}

void add(int l) {
    while(k > 1 && bad(id[k - 2], id[k - 1], l))
        k--;
    id[k] = l;
    k++;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    k = 1;
    p = 0;
    for(int i = 1; i < n; i++) {
        dp[i] = get(a[i]);
        add(i);
    }
    cout << dp[n - 1] << '\n';
    return 0;
}