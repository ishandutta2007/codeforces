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

const int maxn = (int)2e5;
int v[maxn];
ll ans[maxn];

int main() {
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        //v[i] = rand() % maxn;
    }
    
    bool zer = true;
    bool eq = true;
    
    for (int i = 0; i < n; i++) {
        if (v[i] != 0) {
            zer = false;
        }
        
        if (v[i] != v[(i + 1) % n]) {
            eq = false;
        }
    }
    
    if (zer) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("1 ");
        }
        return 0;
    }
    
    if (eq) {
        printf("NO\n");
        return 0;
    }
    
    int pos = -1;
    
    for (int i = 0; i < n; i++) {
        int nx = i + 1;
        
        if (nx == n) {
            nx = 0;
        }
        
        if (v[i] < v[nx]) {
            pos = nx;
            break;
        }
    }
    
    if (pos == -1) {
        throw 1;
    }
    
    if (n == 2) {
        pos = 1 - pos;
        
        v[pos] += v[pos ^ 1];
        
        printf("YES\n");
        
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }
        
        return 0;
    }
    
    ans[pos] = v[pos];
    
    for (int i = pos - 1; i >= 0; i--) {
        int prev = i - 1;
        if (i == 0) {
            prev = n - 1;
        }
        
        ans[i] = v[i];
        
        while (ans[i] <= v[prev]) {
            ans[i] += ans[i + 1];
        }
    }
    
    for (int i = n - 1; i > pos; i--) {
        int nx = i + 1;
        int prev = i - 1;
        
        if (nx == n) {
            nx = 0;
        }
        
        ans[i] = v[i];
        
        while (ans[i] <= v[prev]) {
            ans[i] += ans[nx];
        }
    }
    
    printf("YES\n");
    
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
        
        int nx = i + 1;
        
        if (nx == n) {
            nx = 0;
        }
        
        if (ans[i] % ans[nx] != v[i]) {
            throw 1;
        }
    }
    
    return 0;
}