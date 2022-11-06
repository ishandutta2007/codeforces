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

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

int a[111111];
int vs[111111];

int get(int x) {
    return x == a[x] ? x : a[x] = get(a[x]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (rand() & 1) {
        a[x] = y;
    } else {
        a[y] = x;
    }
}

int main() {
    srand(31);
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, q);
    map<string, int> ws;
    for (int i = 0; i < n; i++) {
        scids(s);
        ws[s] = i;
    }
    
    for (int i = 0; i < n; i++) {
        a[i] = i;
        vs[i] = -1;
    }
    
    for (int i = 0; i < m; i++) {
        scid(t);
        scids(s1, s2);
        int x = get(ws[s1]);
        int y = get(ws[s2]);
        
        int vx = vs[x] == -1 ? -1 : get(vs[x]);
        int vy = vs[y] == -1 ? -1 : get(vs[y]);
        
        if (t == 1) {
            if (vx == y) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            unite(x, y);
            if (vx != -1 && vy != -1) {
                unite(vx, vy);
            }
            if (vx != -1) {
                vs[get(x)] = vx;
            } else if (vy != -1) {
                vs[get(y)] = vy;
            }
        } else {
            if (x == y) {
                cout << "NO\n";
                continue;
            }
            
            if (vx == y) {
                cout << "YES\n";
                continue;
            }
            
            if (vy == -1) {
                swap(x, y);
                swap(vx, vy);
            }
            
            if (vx == -1) {
                vs[x] = y;
                if (vy == -1) {
                    vs[y] = x;
                } else {
                    unite(x, vy);
                    vs[get(x)] = y;
                }
                cout << "YES\n";
                continue;
            }
            
            unite(vx, y);
            vs[get(vx)] = x;
            unite(x, vy);
            vs[get(x)] = y;
            cout << "YES\n";
        }
    }
    
    while (q-- > 0) {
        scids(s1, s2);
        int x = get(ws[s1]);
        int y = get(ws[s2]);
        if (x == y) {
            cout << "1\n";
        } else if (vs[x] != -1 && get(vs[x]) == y) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }

    return 0;
}