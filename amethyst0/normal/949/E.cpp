#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)1e5 + 10;

vector <int> best, cur;

void solve(const vector <int> &v, int st) {
    if (st > 20) {
        return;
    }
    
    vector <int> g;
    
    if (v.empty()) {
        if (cur.size() < best.size()) {
            best = cur;
        }
        
        return;
    }
    
    int last = (int)1e9;
    
    bool fl = false;
    
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] & 1) {
            fl = true;
        }
    }
    
    for (int i = 0; i < (int)v.size(); i++) {
        int x = v[i] >> 1;
        
        if (v[i] & 1) {
            x = (v[i] + 1) >> 1;
        }
        
        if (x != last && x != 0) {
            g.push_back(x);
            last = x;
        }
    }
    
    if (fl) {
        cur.push_back(1 << st);
    }
    
    solve(g, st + 1);
    
    last = (int)1e9;
    
    if (fl) {
        cur.pop_back();
        cur.push_back(-(1 << st));
    }
    
    g.clear();
    
    for (int i = 0; i < (int)v.size(); i++) {
        int x = v[i] >> 1;
        
        if (v[i] & 1) {
            x = (v[i] - 1) >> 1;
        }
        
        if (x != last && x != 0) {
            g.push_back(x);
            last = x;
        }
    }
    
    solve(g, st + 1);
    
    if (fl) {
        cur.pop_back();
    }
}

int main() {
    int n;
    
    cin >> n;
    
    vector <int> v(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    best.resize(40);
    
    sort(v.begin(), v.end());
    
    solve(v, 0);
    
    cout << best.size() << endl;
    
    for (int i = 0; i < (int)best.size(); i++) {
        cout << -best[i] << ' ';
    }
    
    return 0;
}