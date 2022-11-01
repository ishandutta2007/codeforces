#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
vector<int> t(2 * 200000, INF);

int upd(int v, int x) {
    t[v += n] = x;
    for(v >>= 1; v; v >>= 1)
        t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(int l, int r) {
    int ret = INF;
    for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if(l & 1) ret = min(ret, t[l]);
        if(!(r & 1)) ret = min(ret, t[r]);
    }
    return ret;
}

int a[200000], mem[200000], dif;
map<int, int> re;
vector<vector<int>> vv;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        re[a[i]];
        mem[i] = a[i];
    }
    for(map<int, int>::iterator it = re.begin(); it != re.end(); it++)
        it->second = dif++;
    for(int i = 0; i < n; i++)
        a[i] = re[a[i]];
    for(int i = 0; i < n; i++) {
        int id = get(0, a[i]);
        if(id == INF) {
            upd(a[i], vv.size());
            vv.push_back({i}); //  
        } else {
            upd(a[vv[id].back()], INF);
            vv[id].push_back(i);
            upd(a[i], id);
        }
    }
    for(int i = 0; i < vv.size(); i++, cout << '\n')
        for(int x : vv[i])
            cout << mem[x] << ' ';
}