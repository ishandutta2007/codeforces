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
#define ld long double

using namespace std;

ll ans[6];

const ll m = 10004205361450474;

void make(vector <ll> a, ll &l, ll &r) {
    cout << (int)a.size() << endl;
    
    for (int i = 0; i < (int)a.size(); i++) {
        printf("%lld ", a[i]);
    }
    
    printf("\n");
    cout.flush();
    
    int pos;
    
    scanf("%d", &pos);
    
    if (pos == -1) {
        exit(0);
    }
    
    if (pos == -2) {
        cout << "1" << endl;
        throw 1;
    }
    
    if (pos == 0) {
        r = a[0] - 1;
    } else if (pos == (int)a.size()) {
        l = a.back() + 1;
    } else {
        for (int i = 1; i < (int)a.size(); i++) {
            if (pos == i) {
                l = a[i - 1] + 1;
                r = a[i] - 1;
            }
        }
    }
    
    if (l > r) {
        cout << "2" << endl;
        throw 1;
    }
}

ll res[5];

int main() {
    ans[0] = 1;
    ans[1] = (int)1e4;
    
    for (int i = 2; i <= 4; i++) {
        ans[i] = ans[i - 1] * ((int)1e4 + 1) + (int)1e4;
    }
    
    res[0] = 1;
    res[1] = 2047;
    
    for (int i = 2; i <= 3; i++) {
        res[i] = res[i - 1] * ((int)1e4 + 1) + (int)1e4;
    }
    
    vector <ll> g;
    g.push_back(m - ans[4]);
    
    ll l = 1, r = m;
    
    make(g, l, r);
    
    if (l == 1) {
        g.clear();
        g.push_back(2046);
        make(g, l, r);
        
        if (l == 1) {
            g.clear();
            g.push_back(6);
            make(g, l, r);
            if (l == 1) {
                g.clear();
                g.push_back(2);
                make(g, l, r);
                if (l == 1) {
                    g.clear();
                    g.push_back(1);
                    make(g, l, r);
                } else {
                    g.clear();
                    for (int i = 3; i <= 5; i++) {
                        g.push_back(i);
                    }
                    make(g, l, r);
                }
            } else {
                int x = 7;
                g.clear();
                
                for (int i = 0; i < 7; i++) {
                    x += x;
                    g.push_back(x);
                    x++;
                }
                
                make(g, l, r);
                
                if (r - l + 1 > l) {
                    cout << "3" << endl;
                    throw 1;
                }
                
                g.clear();
                
                for (ll i = l; i <= r; i++) {
                    g.push_back(i);
                }
                
                make(g, l, r);
            }
        } else {
            ll x = 2047;
            
            ll y = 20468427;
            
            g.clear();
            
            //ll d = (r - y + 1) / (x);
            ll d = ans[2];
            
            y -= d;
            
            for (int i = 0; i < x; i++) {
                y += d;
                g.push_back(y);
                y++;
            }
            
            make(g, l, r);
            
            if (l == x) {
                ll y = x;
                
                g.clear();
                
                for (int i = 0; i < x; i++) {
                    y += min(y, (ll)1e4);
                    g.push_back(y);
                    y++;
                }
                
                //cout << "!" << l << ' ' << r << endl;
                
                make(g, l, r);
                
                if (r - l + 1 > min(l, (ll)1e4)) {
                    return 0;
                    throw 1;
                }
                
                g.clear();
                
                for (ll i = l; i <= r; i++) {
                    g.push_back(i);
                }
                
                make(g, l, r);
            } else {
                if (r - l + 1 > ans[2]) {
                    throw 1;
                }
                
                for (int k = 1; k >= 1; k--) {
                    g.clear();
            
                    ll cur = l;
                    
                    for (int i = 0; i < (int)1e4; i++) {
                        cur += ans[k];
                        g.push_back(cur);
                        cur++;
                    }
                    
                    make(g, l, r);
                }
                
                if (r - l + 1 > (int)1e4) {
                    return 0;
                    throw 1;
                }
                
                g.clear();
                
                for (ll i = l; i <= r; i++) {
                    g.push_back(i);
                }
                
                make(g, l, r);
            }
        }
    } else {
        for (int k = 3; k >= 1; k--) {
            g.clear();
            
            ll cur = l;
            
            for (int i = 0; i < (int)1e4; i++) {
                cur += ans[k];
                g.push_back(cur);
                cur++;
            }
            
            make(g, l, r);
        }
        
        if (r - l + 1 > (int)1e4) {
            return 0;
            throw 1;
        }
        
        g.clear();
        
        for (ll i = l; i <= r; i++) {
            g.push_back(i);
        }
        
        make(g, l, r);
    }
    
    throw 1;
    
    return 0;
}