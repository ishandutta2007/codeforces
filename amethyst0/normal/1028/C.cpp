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

const int maxn = (int)2e5 + 10;
pair <pii, pii> v[maxn];

int n;

const int inf = (int)1e9;

void go(int pos) {
    int l1 = -inf;
    int r1 = inf;
    int l2 = -inf;
    int r2 = inf;
    
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            continue;
        }
        
        l1 = max(l1, v[i].first.first);
        r1 = min(r1, v[i].second.first);
        l2 = max(l2, v[i].first.second);
        r2 = min(r2, v[i].second.second);
    }
    
    if (l1 <= r1 && l2 <= r2) {
        cout << l1 << ' ' << l2 << endl;
        exit(0);
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        v[i] = mp(mp(x1, y1), mp(x2, y2));
    }
    
    int pos = 0;
    
    for (int i = 1; i < n; i++) {
        if (v[i].first.first > v[pos].first.first) {
            pos = i;
        }
    }
    
    go(pos);
    
    pos = 0;
    
    for (int i = 1; i < n; i++) {
        if (v[i].second.first < v[pos].second.first) {
            pos = i;
        }
    }
    
    go(pos);
    
    pos = 0;
    
    for (int i = 1; i < n; i++) {
        if (v[i].first.second > v[pos].first.second) {
            pos = i;
        }
    }
    
    go(pos);
    
    pos = 0;
    
    for (int i = 1; i < n; i++) {
        if (v[i].second.second < v[pos].second.second) {
            pos = i;
        }
    }
    
    go(pos);
    
    throw 1;
}