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

int a[222222];
int b[222222];
int pr[222222];

vector<pair<int, int> > c[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i], b[i]);
        c[a[i]].push_back({i, b[i]});
    }
    
    set<int> w;
    for (int i = n - 1; i >= 0; ) {
        w.insert(a[i]);
        int x = i - 1;
        while (x >= 0 && w.find(a[x]) != w.end()) {
            x--;
        }
        pr[i] = x;
        i = x;
    }
    
    scid(q);
    while (q-- > 0) {
        scid(k);
        set<int> s;
        for (int i = 0; i < k; i++) {
            scid(x);
            s.insert(x);
        }
        
        int win = 0;
        int bet = 0;
        for (int i = n - 1; i >= 0; i = pr[i]) {
            if (s.find(a[i]) == s.end()) {
                win = a[i];
                
                int x = pr[i];
                while (x >= 0 && s.find(a[x]) != s.end()) {
                    x = pr[x];
                }
                
                int id = upper_bound(c[a[i]].begin(), c[a[i]].end(), make_pair(x, 0)) - c[a[i]].begin();
//                cout << pr[i] << endl;
                bet = c[a[i]][id].second;
                
                break;
            }
        }
        cout << win << " " << bet << "\n";
    }

    return 0;
}