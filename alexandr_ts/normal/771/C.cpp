#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef long double ld;
using namespace std;

struct state {
    ll sum[5], cnt[5];
    state() {
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
    }
};

const int MAXN = 2 * 100000;
vector<int> g[MAXN + 1];
int k;
unsigned long long ans = 0;

state dfs(int v, int p) {
    state cur;
    bool was = false;
    //ll ans = 0;
    for(auto u: g[v]) {
        if(u == p)
            continue;
        state temp = dfs(u, v);
        rotate(temp.sum, temp.sum + k - 1, temp.sum + k);
        rotate(temp.cnt, temp.cnt + k - 1, temp.cnt + k);
        if(k > 1) {
            temp.cnt[1] += 1;
        }
        else {
            temp.cnt[0] += 1;
        }
        for(int i = 0; i < k; i++)
            temp.sum[i] += temp.cnt[i];
        for(int i = 0; i < k; i++) {
            //cout << v << " " << i << " " << temp.sum[i] << " " << temp.cnt[i] << "\n";
            ans += (temp.sum[i] - temp.cnt[i] * i) / k;
            if(i > 0)
                ans += temp.cnt[i];
        }
        if(!was)
            cur = temp, was = true;
        else {
            for(int i = 0; i < k; i++) {
                for(int j = 0; j < k; j++) {
                    int calc = i + j;
                    if(calc >= k)
                        calc -= k;
                    ans += (cur.sum[i] * temp.cnt[j] + cur.cnt[i] * temp.sum[j] - calc * cur.cnt[i] * temp.cnt[j]) / k;
                    if(calc > 0)
                        ans += (cur.cnt[i] * temp.cnt[j]);
                }
            }
            for(int i = 0; i < k; i++) {
                cur.sum[i] += temp.sum[i], cur.cnt[i] += temp.cnt[i];
            }
        }
    }
    //cout << v << " " << ans << "\n";
    return cur;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    cout << ans << "\n";
    return 0;
}