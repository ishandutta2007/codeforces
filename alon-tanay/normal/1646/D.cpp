#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define ppi pair<int,pi>
#define MOD 1000000007
#define f first
#define s second

using namespace std;

pi dp[200002];
pi dp_bl[200002];
bool used[200002];
vector<int> nei[200002];
int deg[200002];

void rec(int node = 1, int par = -1) {
    dp[node] = {1,deg[node]};
    dp_bl[node] = {0,1};
    for(int ne : nei[node]) {
        if(ne == par) { continue; }
        rec(ne,node);
        dp[node].f += dp_bl[ne].f;
        dp[node].s += dp_bl[ne].s;
        if(dp[ne].f > dp_bl[ne].f || (dp[ne].f == dp_bl[ne].f && dp[ne].s < dp_bl[ne].s)) {
            dp_bl[node].f += dp[ne].f;
            dp_bl[node].s += dp[ne].s;
        } else {
            dp_bl[node].f += dp_bl[ne].f;
            dp_bl[node].s += dp_bl[ne].s;
        }
    }
}

void rec2(int node = 1, int par = -1, bool bl = false) {
    if(bl) {
        for(int ne : nei[node]) {
            if(ne == par) { continue; }
            rec2(ne,node,false);
        }
    } else {
        if(dp[node].f > dp_bl[node].f || (dp[node].f == dp_bl[node].f && dp[node].s < dp_bl[node].s)) {
            used[node] = true;
            for(int ne : nei[node]) {
                if(ne == par) { continue; }
                rec2(ne,node,true);
            }
        } else {
            for(int ne : nei[node]) {
                if(ne == par) { continue; }
                rec2(ne,node,false);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        deg[a] ++;
        deg[b] ++;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    if(n == 2) {
        cout << "2 2\n1 1\n";
        return 0;
    }
    rec();
    rec2();
    vector<int> res(n+1);
    ll total = 0;
    for(int i = 1; i<= n; i ++) {
        res[i] = (used[i] ? deg[i] : 1);
        total += res[i];
    }
    if(dp[1].f > dp_bl[1].f || (dp[1].f == dp_bl[1].f && dp[1].s < dp_bl[1].s)) {
        cout << dp[1].f << " " << dp[1].s << "\n";
    } else {
        cout << dp_bl[1].f << " " << dp_bl[1].s << "\n";
    }
    for(int i = 1; i <= n; i ++) {
        cout << res[i] << " ";
    }
    return 0;
}