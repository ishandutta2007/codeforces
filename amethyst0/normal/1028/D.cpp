#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <time.h>
#define ll long long
#define mp make_pair
#define pii pair <int, int>

using namespace std;

const int maxn = (int)4e5;

char f[30];

set <int> u, b, s;

int go_tp(int x) {
    int tp = -1;
    
    if (!b.empty() && x <= (*b.rbegin())) {
        tp = 0;
    }
    
    if (!s.empty() && x >= (*s.begin())) {
        if (tp != -1) {
            cout << 0 << endl;
            exit(0);
        }
        
        tp = 1;
    }
    
    return tp;
}

const int mod = (int)1e9 + 7;

int main() {
    int n;
    
    cin >> n;
    
    int ans = 1;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", f);
        int x;
        
        scanf("%d", &x);
        
        if (f[1] == 'D') {
            int tp = go_tp(x);
            
            if (tp == 0) {
                b.insert(x);
            } else if (tp == 1) {
                s.insert(x);
            } else {
                u.insert(x);
            }
        } else {
            if (s.count(x) && (*s.begin()) != x) {
                cout << 0 << endl;
                return 0;
            }
            
            if (b.count(x) && (*b.rbegin()) != x) {
                cout << 0 << endl;
                return 0;
            }
            
            set <int>::iterator it;
            for (it = u.begin(); it != u.end(); it++) {
                if ((*it) < x) {
                    b.insert(*it);
                } else if ((*it) > x) {
                    s.insert(*it);
                } else {
                    ans <<= 1;
                    if (ans >= mod) {
                        ans -= mod;
                    }
                }
            }
            
            u.clear();
            s.erase(x);
            b.erase(x);
        }
    }
    
    if (!u.empty()) {
        ans = (ll)ans * (u.size() + 1) % mod;
    }
    
    cout << ans << endl;
    
    return 0;
}