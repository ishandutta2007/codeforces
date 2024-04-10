#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <map>
#include <vector>
#define ll long long
#define pii pair <ll, int>
#define mp make_pair

using namespace std;

const int maxn = (int)2e5 + 10;

pii dp[maxn][2];
vector <int> ed[maxn];

pii operator +(pii a, pii b) {
    a.first += b.first;
    a.second += b.second;
    
    return a;
}

pii operator -(pii a, pii b) {
    a.first -= b.first;
    a.second -= b.second;
    
    return a;
}

void dfs(int v, int p) {
    dp[v][0] = mp(0, 1);
    
    for (int i = 0; i < (int)ed[v].size(); i++) {
        int u = ed[v][i];
        
        if (u == p) {
            continue;
        }
        
        dfs(u, v);
        dp[v][0] = dp[v][0] + dp[u][1];
        dp[v][0].first += dp[u][1].second;
        dp[v][1] = dp[v][1] + dp[u][0];
        dp[v][1].first += dp[u][0].second;
    }
}

ll ans = 0;

void go(int v, int p, pii a, pii b) {
    ans += dp[v][0].first / 2;
    ans += (dp[v][1].first + dp[v][1].second) / 2;
    ans += (a.first) / 2;
    ans += (b.first + b.second) / 2;
    
    swap(a, b);
    a.first += a.second;
    b.first += b.second;
    
    b.first += 1;
    b.second += 1;
    
    for (int i = 0; i < (int)ed[v].size(); i++) {
        int u = ed[v][i];
        
        if (u != p) {
            pii cur = dp[u][0];
            cur.first += 2 * cur.second;
            a = a + cur;
            cur = dp[u][1];
            cur.first += 2 * cur.second;
            b = b + cur;
        }
    }
    
    for (int i = 0; i < (int)ed[v].size(); i++) {
        int u = ed[v][i];
        
        if (u != p) {
            pii cur = dp[u][0];
            cur.first += 2 * cur.second;
            pii cur1 = dp[u][1];
            cur1.first += 2 * cur1.second;
            
            go(u, v, a - cur, b - cur1);
        }
    }
}

int main() {
    int n;
    
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    
    dfs(1, 1);
    
    go(1, 1, mp(0, 0), mp(0, 0));

    cout << ans / 2 << endl;

    return 0;
}