#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int l[n + 1], r[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    vector<bool> was(n + 1, false);
    vector<int> x, y;
    for(int i = 1; i <= n; i++)
        if(!was[i]) {
            was[i] = true;
            int v = i;
            while(r[v] != 0) { v = r[v]; was[v] = true; }
            int u = i;
            while(l[u] != 0) { u = l[u]; was[u] = true; }
            x.push_back(u);
            y.push_back(v);
        }
    while(x.size() != 1) {
        int v = x.back();
        x.pop_back();
        y.pop_back();
        int u = y.back();
        l[v] = u;
        r[u] = v;
    }
    for(int i = 1; i <= n; i++)
        cout << l[i] << ' ' << r[i] << endl;
}