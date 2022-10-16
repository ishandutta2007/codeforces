#include <bits/stdc++.h>

using namespace std;

const int NMAX = 300 + 5;
const int VALMAX = 100000 + 5;
const int MOD = 1000000000 + 7;

int N, Q, t;
int w[NMAX];
int edge[NMAX];
bool someoneLeaves[NMAX];
bool vis[NMAX];

int parc(int node) {
    if (vis[node]) {
        cout << "0\n";
        exit(0);
    }
    vis[node] = true;
    int sum = 0;
    if (edge[node]) {
        sum += parc(edge[node]);
        t -= sum;
        if (t < 0) {
            cout << "0\n";
            exit(0);
        }
    }
    w[node] += sum;
    if (w[node] > VALMAX)
        w[node] = VALMAX;
    return w[node];
}

int ans[VALMAX];

int main() {
    ios_base :: sync_with_stdio(false);
    //freopen("data.in", "r", stdin);

    cin >> N >> Q >> t;
    for (int i = 1; i <= N; ++ i)
        cin >> w[i];
    while (Q --) {
        int a, b;
        cin >> a >> b;
        edge[b] = a;
        someoneLeaves[a] = true;
    }

    for (int i = 1; i <= N; ++ i)
        if (!someoneLeaves[i])
            parc(i);
    for (int i = 1; i <= N; ++ i)
        if (!vis[i]) {
            cout << "0\n";
            return 0;
        }

    if (t < 0) {
        cout << "0\n";
        return 0;
    }

    ans[0] = 1;
    for (int i = 1; i <= N; ++ i)
        for (int j = 0; j <= t; ++ j)
            if (j + w[i] <= t) {
                ans[j + w[i]] += ans[j];
                if (ans[j + w[i]] >= MOD)
                    ans[j + w[i]] -= MOD;
            }
    cout << ans[t] << endl;
    return 0;
}