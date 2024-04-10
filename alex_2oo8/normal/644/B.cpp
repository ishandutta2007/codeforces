#include<bits/stdc++.h>

using namespace std;

long long e[200000];

int main() {
    int n, b, l = 0, r = 0;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);
        
        while (l < r && e[l] <= t) l++;
        
        if (r - l == b + 1) printf("-1 ");
        else {
            e[r] = (l == r ? t : e[r - 1]) + d;
            
            printf("%lld ", e[r]);
            
            r++;
        }
    }
    
    printf("\n");
    
    return 0;
}