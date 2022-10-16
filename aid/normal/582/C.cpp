#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int a[2 * MAXN], x[MAXN], nxt[2 * MAXN], pi[MAXN];

bool periodic(int n) {
    pi[0] = 0;
    for(int i = 1; i < n; i++) {
        pi[i] = pi[i - 1];
        while(pi[i] > 0 && x[i] != x[pi[i]])
            pi[i] = pi[pi[i] - 1];
        if(x[i] == x[pi[i]])
            pi[i]++;
    }
    return pi[n - 1] != 0 && n % (n - pi[n - 1]) == 0;
}

long long solve(int n, int d) {
    if(d == n)
        return 0;
    for(int i = 0; i < d; i++)
        x[i] = 0;
    for(int i = 0; i < n; i++)
        x[i % d] = max(x[i % d], a[i]);
    if(periodic(d))
        return 0;
    nxt[2 * n - 1] = (a[2 * n - 1] == x[(2 * n - 1) % d]? 2 * n : 2 * n - 1);
    for(int i = 2 * n - 2; i >= 0; i--)
        nxt[i] = (a[i] == x[i % d]? nxt[i + 1] : i);
    long long res = 0;
    for(int i = 0; i < n; i++) {
        int l = nxt[i] - i;
        l = min(l, n - 1);
        res += l / d;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = n; i < 2 * n; i++)
        a[i] = a[i - n];
    long long ans = 0;
    for(int i = 1; i * i <= n; i++)
        if(!(n % i)) {
            ans += solve(n, i);
            if(i * i != n)
                ans += solve(n, n / i);
        }
    cout << ans << '\n';
    return 0;
}