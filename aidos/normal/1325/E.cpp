#include <bits/stdc++.h>

using namespace std;
const int maxn = (int)1e6 + 100;
int n, m;
int a[maxn];
int d[maxn];
int pr[maxn];
vector<int> g[maxn];
int T;
int used[maxn];
int dis[maxn];
int p[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    for(int i = 1; i < maxn; i++) {
        d[i] = i;
        pr[i] = i;
    }
    for(int i = 2; i < maxn; i++) {
        if(pr[i] == i) {
            for (int j = i; j < maxn; j += i) {
                if ((j / i) % i == 0) {
                    d[j] = d[j / i / i];
                }
                pr[j] = i;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = d[a[i]];
    }
    sort(a, a + n);
    if(a[0] == 1) {
        cout << 1 << "\n";
        return 0;
    }
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            cout << 2 << "\n";
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        int x = a[i]/pr[a[i]];
        g[x].push_back(pr[a[i]]);
        g[pr[a[i]]].push_back(x);
    }
    int ans = maxn;
    for(int i = 1; i*i < maxn; i++) {
        if(g[i].size()==0) continue;
        T++;
        queue<int> q;
        q.push(i);
        used[i] = T;
        dis[i] = 0;
        p[i] = -1;
        while(q.size() > 0) {
            int v = q.front();
            q.pop();
            if(dis[v] >= ans) break;
            for(int to: g[v]) {
                if(used[to] == T) {
                    if(p[v] != to) {
                        ans = min(ans, dis[to] + dis[v] + 1);
                    }
                } else {
                    p[to] = v;
                    q.push(to);
                    used[to] = T;
                    dis[to] = dis[v] + 1;
                }
            }
        }
    }
    if(ans == maxn) ans = -1;
    cout << ans << "\n";
}