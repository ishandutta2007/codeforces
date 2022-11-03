#include <bits/stdc++.h>
#define fir first
#define sec second
#define pb push_back
using namespace std;
#define int ll
typedef long long ll;

const int MAX_N = 5e4 + 100;
int answer, n, k;
int dpDown[MAX_N][510];
int pr[510];
vector<int> vec[MAX_N];

void dfs(int u, int pred = -1) {
    for (auto i:vec[u])
        if (i != pred) {
            dfs(i, u);
        }

    dpDown[u][0] = 1;
    for (int i = 0; i <= k; i++)
        pr[i] = 0;
    pr[0] = 1;


    for (auto i:vec[u])
        if (i != pred) {
            for (int j = 1; j <= k; j++) {
                dpDown[u][j] += dpDown[i][j - 1];
                answer += pr[k - j] * dpDown[i][j - 1];
            }
            for (int j = 1; j <= k; j++) {
                pr[j] += dpDown[i][j - 1];
            }
        }

}

main() {

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    dfs(1);

    cout << answer;
}