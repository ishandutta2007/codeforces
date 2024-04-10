#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500 * 1000 + 5;
pair<char, pair<int, int> > q[MAXN];
int p[MAXN], ts[MAXN], lst[MAXN], lstupd[MAXN];
long long val[MAXN], add[MAXN], ans[MAXN];
vector<int> comp[MAXN];
vector< pair<int, int> > qq[MAXN];

int get(int x) {
    return x == p[x]? x : get(p[x]);
}

void unite0(int x, int y, int t) {
    x = get(x);
    y = get(y);
    if(ts[x] < ts[y])
        swap(x, y);
    p[y] = x;
    ts[x] += ts[y];
    for(size_t i = 0; i < comp[y].size(); i++) {
        int v = comp[y][i];
        if(lstupd[v] < lst[y])
            lst[v] = lst[y];
        lstupd[v] = t;
        comp[x].push_back(v);
    }
    comp[y].clear();
}

void unite1(int x, int y) {
    x = get(x);
    y = get(y);
    if(ts[x] < ts[y])
        swap(x, y);
    p[y] = x;
    ts[x] += ts[y];
    for(size_t i = 0; i < comp[y].size(); i++) {
        int v = comp[y][i];
        val[v] += add[y] - add[x];
        comp[x].push_back(v);
    }
    comp[y].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> q[i].first;
        if(q[i].first == 'U' || q[i].first == 'M') {
            cin >> q[i].second.first >> q[i].second.second;
            q[i].second.first--;
            q[i].second.second--;
        }
        else {
            cin >> q[i].second.first;
            q[i].second.first--;
            q[i].second.second = -1;
        }
    }
    for(int i = 0; i < n; i++) {
        p[i] = i;
        ts[i] = 1;
        lst[i] = 0;
        lstupd[i] = 0;
        comp[i].push_back(i);
    }
    for(int i = 0; i < m; i++) {
        char c = q[i].first;
        if(c == 'U')
            continue;
        else if(c == 'M') {
            int x = q[i].second.first, y = q[i].second.second;
            unite0(x, y, i);
        }
        else if(c == 'A')
            continue;
        else if(c == 'Z') {
            int x = q[i].second.first;
            lst[get(x)] = i;
        }
        else {
            int x = q[i].second.first, root = get(x), t;
            if(lstupd[x] < lst[root])
                t = lst[root];
            else
                t = lst[x];
            qq[t].push_back(make_pair(x, i));
        }
    }
    for(int i = 0; i < n; i++) {
        p[i] = i;
        ts[i] = 1;
        val[i] = 0;
        add[i] = 0;
        comp[i].clear();
        comp[i].push_back(i);
    }
    for(int i = 0; i < m; i++) {
        for(size_t j = 0; j < qq[i].size(); j++) {
            int x = qq[i][j].first, id = qq[i][j].second;
            ans[id] -= val[x] + add[get(x)];
        }
        char c = q[i].first;
        if(c == 'U') {
            int x = q[i].second.first, y = q[i].second.second;
            unite1(x, y);
        }
        else if(c == 'M')
            continue;
        else if(c == 'A') {
            int x = get(q[i].second.first);
            add[x] += ts[x];
        }
        else if(c == 'Z')
            continue;
        else {
            int x = q[i].second.first;
            ans[i] += val[x] + add[get(x)];
        }
    }
    for(int i = 0; i < m; i++)
        if(q[i].first == 'Q')
            cout << ans[i] << '\n';
    return 0;
}