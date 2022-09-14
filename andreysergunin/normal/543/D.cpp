#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;
    
const int MAXN = 500000;
const int P = 1e9 + 7;
long long t[MAXN];
vector<int> edge[MAXN];
vector<long long> ans;

void dfs(int v, int a) {
    t[v] = 1;
    for (int i = 0; i < (int)edge[v].size(); i++) {
        if (edge[v][i] != a) {
            dfs(edge[v][i], v);
            t[v] = (t[v] * (1 + t[edge[v][i]])) % P;
        }
    }
}

long long st(long long a, long long b) {
    if (b == 0)
        return 1;
    long long t = st(a, b / 2);
    long long ans = (t * t) % P;
    if (b % 2 == 1)
        ans = (ans * a) % P;
    return ans;
}

void dfs1 (int v, int a) {
    ans[v] = t[v];
    vector<long long> suff(edge[v].size()), pref(edge[v].size());
    for (int i = 0; i < edge[v].size(); i++) {
        if (i == 0)
            suff[i] = 1;
        else
            suff[i] = (suff[i - 1] * (t[edge[v][i - 1]] + 1)) % P;
    }
    for (int i = (int)edge[v].size() - 1; i >= 0; i--) {
        if (i == (int)edge[v].size() - 1)
            pref[i] = 1;
        else
            pref[i] = (pref[i + 1] * (t[edge[v][i + 1]] + 1)) % P;
    }
    for (int i = 0; i < (int)edge[v].size(); i++) {
        if (edge[v][i] == a)
            continue;
        long long x = t[v], y = t[edge[v][i]];
        t[v] = (pref[i] * suff[i]) % P;
        t[edge[v][i]] = (t[edge[v][i]] * (t[v] + 1)) % P;
        dfs1(edge[v][i], v);
        t[v] = x;
        t[edge[v][i]] = y;
    }

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i]--;
        edge[a[i]].push_back(i);
        edge[i].push_back(a[i]);
    }
    dfs(0, -1);
    ans.resize(n);
    dfs1(0, -1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}