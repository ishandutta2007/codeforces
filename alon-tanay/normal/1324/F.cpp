#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second
#define vvi vector<vi>
#define vvl vector<vl>

using namespace std;
using namespace __gnu_pbds;

const int mxN = 200005;

int val[mxN];
vector<int> nei[mxN];
int dp1[mxN];
int dp2[mxN];

void dfs(int node, int par = 0) {
    dp1[node] = val[node];
    for(int ne: nei[node]) {
        if(ne == par) { continue; }
        dfs(ne,node);
        dp1[node] += max(0,dp1[ne]);
    }
}

void dfs2(int node, int par = 0) {
    if(dp1[node] < 0) {
        dp2[node] = max(dp1[node],dp2[par]+dp1[node]);
    } else {
        dp2[node] = max(dp1[node],dp2[par]);
    }
    // int id = -1;
    for(int ne: nei[node]) {
        // id ++;
        if(ne == par) { continue; }
        dfs2(ne,node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        x *= 2;
        x --;
        val[i] = x;
    }
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    dfs(1);
    dfs2(1);
    for(int i = 1; i <= n; i ++) {
        cout << dp2[i] << " ";
    }
    return 0;
}