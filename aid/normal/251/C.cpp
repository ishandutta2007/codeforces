#include <iostream>
#include <queue>

using namespace std;

const int MAXM = 400 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int d[MAXM];

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int bfs(int s, int t, int k, int m) {
    for(int i = 0; i < m; i++)
        d[i] = INF;
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if(v && d[v - 1] > d[v] + 1) {
            d[v - 1] = d[v] + 1;
            q.push(v - 1);
        }
        for(int i = 2; i <= k; i++) {
            int u = v - v % i;
            if(d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return d[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    long long a, b;
    int k;
    cin >> a >> b >> k;
    int m = 1;
    for(int i = 2; i <= k; i++)
        m = lcm(m, i);
    if(a / m == b / m) {
        cout << bfs(a % m, b % m, k, m) << '\n';
        return 0;
    }
    long long ans = bfs(a % m, 0, k, m) + bfs(m - 1, b % m, k, m) + 1;
    a -= a % m;
    b += m - b % m;
    ans += (bfs(m - 1, 0, k, m) + 1) * ((a - b) / m);
    cout << ans << '\n';
    return 0;
}