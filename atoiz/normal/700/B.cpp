#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> cntSub, height;
vector< vector<int> > gr;
vector<bool> isUni;
int root = -1, n, k;

void dfsRoot(int u, int par) {
    cntSub[u] = (isUni[u]);

    bool isRoot = 1;
    for (int v : gr[u]) {
        if (v == par) continue;
        dfsRoot(v, u);
        cntSub[u] += cntSub[v];
        if (cntSub[v] > k) isRoot = 0;
    }

	isRoot &= (root < 0);
    isRoot &= (cntSub[u] >= k);

    if (isRoot) root = u;
}

void dfsHeight(int u, int par, int curH)
{
    height[u] = curH++;
    for (int v : gr[u]) {
        if (v == par) continue;
        dfsHeight(v, u, curH);
    }
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    vector<int> uni(2*k);
    isUni.assign(n+1, 0);
    for (int i = 0; i < 2*k; ++i) {
        cin >> uni[i];
        isUni[uni[i]] = 1;
    }

    gr.resize(n+1);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    cntSub.assign(n+1, 0);
    dfsRoot(1, -1);

//    if (root < 0) return 8319;
//    cerr << root << endl;

    height.assign(n+1, 0);
    dfsHeight(root, -1, 0);

    long long ans = 0;
    for (int u : uni) ans += height[u];
    cout << ans << endl;
}