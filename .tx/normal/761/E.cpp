#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int d[33];
vector<int> g[33];
lint ansx[33];
lint ansy[33];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int opp(int i) {
    if (i <= 1) {
        return 1 - i;
    }
    return 5 - i;
}

void dfs(int v, int p, lint x, lint y, lint c, int fb) {
    int cd = 0;
    ansx[v] = x;
    ansy[v] = y;
    
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        while (cd == fb) {
            cd++;
        }
        dfs(i, v, x + c * dx[cd], y + c * dy[cd], c / 3, opp(cd));
        cd++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);       
    lint p = 1;
    for (int i = 0; i < 35; i++) {
        p *= 3;
    }
    
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        d[x]++;
        d[y]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (d[i] > 4) {
            cout << "NO";
            return 0;
        }
    }
    
    dfs(0, -1, 0, 0, p, -1);
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ansx[i] << " " << ansy[i] << "\n";
    }
    

    return 0;
}