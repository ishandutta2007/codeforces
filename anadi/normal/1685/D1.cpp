#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 207;
const int MOD = 1'000'000'007;

int n;
int p[N];
int in[N];
bool vis[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);
        in[i] = v;

        p[v] = i;
        vis[i] = false;
    }

    vector <int> ans = {};
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) 
            continue;

        vector <int> cur;
        int u = i;

        while (!vis[u]) {
            vis[u] = true;
            cur.push_back(u);
            u = p[u];
        }

        if (ans.empty()) {
            ans = cur;
            continue;
        }

        int pos = -1;
        for (int j = 0; true; ++j) {
            if (ans[j] == i - 1) {
                pos = j;
                break;
            }
        }

        ans.insert(ans.begin() + pos + 1, cur.begin(), cur.begin() + 1);
        ans.insert(ans.begin() + pos + 1, cur.begin() + 1, cur.end());
    }

    int val = 0;
    for (int i = 0; i < n; ++i) {
        val += abs(ans[i] - in[ans[(i + 1) % n]]);
        printf("%d ", ans[i]);
    }

    puts("");
    //fprintf(stderr, "score = %d\n", val);
//    printf("%d\n", val);
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}