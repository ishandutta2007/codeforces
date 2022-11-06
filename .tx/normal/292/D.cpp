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

struct Dsu {
    int *a;
    int cc;
    
    Dsu() {}
    
    Dsu(int n) {
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
        cc = n;
    }
    
    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }
    
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            cc--;
            if (rand() & 1) {
                a[x] = y;
            } else {
                a[y] = x;
            }
        }
    }
};

pair<int, int> es[11111];
Dsu dl[111111];
Dsu dr[111111];

int main() {
    srand(31);
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        es[i] = {x, y};
    }
    
    dl[0] = Dsu(n);
    for (int i = 1; i <= m; i++) {
        dl[i] = Dsu(n);
        memcpy(dl[i].a, dl[i - 1].a, sizeof(int) * n);
        dl[i].cc = dl[i - 1].cc;
        dl[i].unite(es[i - 1].first, es[i - 1].second);
    }
    
    dr[m] = Dsu(n);
    for (int i = m - 1; i >= 0; i--) {
        dr[i] = Dsu(n);
        memcpy(dr[i].a, dr[i + 1].a, sizeof(int) * n);
        dr[i].cc = dr[i + 1].cc;
        dr[i].unite(es[i].first, es[i].second);
    }
    
    scid(k);
    
    Dsu tt(n);
    
    while (k-- > 0) {
        scid(l, r);
        --l; --r;
        
        memcpy(tt.a, dl[l].a, sizeof(int) * n);
        tt.cc = dl[l].cc;
        
        for (int i = 0; i < n; i++) {
            int x = dr[r + 1].get(i);
            tt.unite(i, x);
        }
        
        cout << tt.cc << "\n";
    }
    
    

    return 0;
}