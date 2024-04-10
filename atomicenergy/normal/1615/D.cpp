using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

struct uf {
    vector<int> rt, sz, pr;

    uf(int n) {
        rt.resize(n);
        sz.resize(n);
        pr.resize(n);
        for (int i = 0; i < n; i++) {
            rt[i] = i;
            sz[i] = 1;
            pr[i] = 0;
        }
    }

    int id(int x) {
        if (rt[x] == x) return x;
        int a = id(rt[x]);
        pr[x] ^= pr[rt[x]];
        rt[x] = a;
        return rt[x];
    }

    bool join(int x, int y, bool c) {
        x = id(x);
        y = id(y);
        if (x == y) return false;
        rt[x] = rt[y];
        pr[x] = c;
        sz[y] += sz[x];
        sz[x] = 0;
        return true;
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n, q;
        cin >> n >> q;
        uf u(n + 1);

        vector<pair< pair<int, int>, int > > v;
        for(int i = 0; i<n-1; i++){
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({{a, b}, c});
            if(c != -1){
                int d = 0;
                while(c > 0){
                    d ^= (c%2);
                    c/=2;
                }
                u.id(a);
                u.id(b);
                u.join(a, b, u.pr[a] ^ u.pr[b] ^ d);
            }
        }
        bool ok = true;
        for(int i=0; i<q; i++){
            int a, b, c;
            cin >> a >> b >> c;
            //cout << a << " " << b << " " << u.id(a) << " " << u.pr[a] << " " << u.id(b) << " " << u.pr[b] << endl;
            if(u.id(a) == u.id(b)){
                if(u.pr[a] ^ u.pr[b] != c){
                    ok = false;
                }
            }else{
                u.join(a, b, u.pr[a] ^ u.pr[b] ^ c);
            }
        }
        if(!ok){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(auto p : v){
            if(p.second != -1){
                cout << p.first.first << " " << p.first.second << " " << p.second << endl;
            }else{
                if(u.id(p.first.first) != u.id(p.first.second)){
                    
                        u.join(p.first.first, p.first.second, 0);
                    
                }

                cout << p.first.first << " " << p.first.second << " " << (u.pr[p.first.first] ^ u.pr[p.first.second]) << endl;
            }
        }

    }
    
}