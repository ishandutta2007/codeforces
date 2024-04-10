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
#define ll long long

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];
int mins[maxn], maxs[maxn];
int ans[maxn];

int main() {
    int n, q;
    
    cin >> n >> q;
    
    set <int> ps;
    int w = -1;
    
    for (int i = 1; i <= q; i++) {
        mins[i] = n + 1;
        maxs[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        
        mins[v[i]] = min(mins[v[i]], i);
        maxs[v[i]] = max(maxs[v[i]], i);
        ps.insert(i);
        
        if (v[i] != 0) {
            ans[i] = v[i];
        } else {
            w = i;
        }
    }
    
    for (int i = q; i >= 1; i--) {
        if (maxs[i] == -1) {
            if (w == -1) {
                printf("NO\n");
                return 0;
            } else {
                mins[i] = w;
                maxs[i] = w;
            }
        }
        
        int l = mins[i];
        int r = maxs[i];
        
        set<int>::iterator it = ps.lower_bound(l);
        
        while (it != ps.begin()) {
            set<int>::iterator nit = it;
            nit--;
            
            if (v[*nit] == 0) {
                it--;
            } else {
                break;
            }
        }
        
        while (it != ps.end() && (*it) <= r) {
            set<int>::iterator nit = it;
            w = (*it);
            if (v[*it] == 0) {
                ans[*it] = i;
                it++;
            } else if (v[*it] != i) {
                printf("NO\n");
                return 0;
            } else {
                it++;
            }
            ps.erase(nit);
        }
        
        while (it != ps.end() && v[*it] == 0) {
            set<int>::iterator nit = it;
            ans[*it] = i;
            it++;
            ps.erase(nit);
        }
    }
    
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}