#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 2005;

int n, u, ans = 0;
vector<int> a[MN], st;

void dfs(int cur, int d) {
    ans = max(ans, d);
    for (int nxt : a[cur]) dfs(nxt, d + 1);
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        if (u == -1) {st.push_back(i); continue;}
        a[u].push_back(i);
    }
    for (int cur : st) dfs(cur, 1);
    printf("%d\n", ans);

    return 0;
}