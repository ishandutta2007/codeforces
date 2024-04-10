#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <map>
#include <vector>
#define ll long long
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = 2010;
int a[maxn], b[maxn];

int d[maxn];
int e[maxn];

int main() {
    int n, m;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        if (i != 0) {
            a[i] += a[i - 1];
        }
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        
        if (i != 0) {
            b[i] += b[i - 1];
        }
    }
    
    int x;
    
    cin >> x;
    
    for (int len = 1; len <= n; len++) {
        d[len] = (int)1e9;
        
        for (int i = 0; i <= n - len; i++) {
            int now = a[i + len - 1];
            
            if (i != 0) {
                now -= a[i - 1];
            }
            
            d[len] = min(d[len], now);
        }
    }
    
    for (int len = 1; len <= m; len++) {
        e[len] = (int)1e9;
        
        for (int i = 0; i <= m - len; i++) {
            int now = b[i + len - 1];
            
            if (i != 0) {
                now -= b[i - 1];
            }
            
            e[len] = min(e[len], now);
        }
    }
    
    int r = m;
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        while (r > 0 && (ll)d[i] * e[r] > x) {
            r--;
        }
        
        ans = max(ans, i * r);
    }
    
    cout << ans << endl;
    
    return 0;
}