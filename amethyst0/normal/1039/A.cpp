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
ll b[maxn];
ll a[maxn];
int f[maxn];

int main() {
    int n;
    
    cin >> n;
    ll t;
    
    cin >> t;
    
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        b[i] = a[i] + t;
    }

    int pos = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        x--;
        f[i] = x;
        
        if (x < i) {
            printf("No\n");
            return 0;
        }
        
        pos = max(pos, i);
        
        while (pos < x) {
            b[pos] = a[pos + 1] + t;
            pos++;
        }
    }
    
    for (int i = 1; i < n; i++) {
        b[i] = max(b[i], b[i - 1] + 1);
    }
    
    for (int i = 0; i < n; i++) {
        int x = f[i];
        
        if (x == n - 1) {
            continue;
        }
        
        if (b[x] >= a[x + 1] + t) {
            printf("No\n");
            return 0;
        }
    }
    
    printf("Yes\n");
    
    for (int i = 0; i < n; i++) {
        printf("%I64d ", b[i]);
    }
    
    printf("\n");
    
    return 0;
}