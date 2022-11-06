#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, m, a, b;
int s[MAXN];

void read(){
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(int i = 1; i <= m; ++i){
        scanf("%d", s + i);
    }
}

void work(){
    sort(s + 1, s + 1 + m);
    int ans, t;
    if(a < b) ans = b - a - 1, t = b - 1;
    else ans = a - b - 1, t = n - b;

    int i, mx = 0;
    for(i = 1; i <= m; ++i){
        mx = max(mx + 1, s[i] + 1);
        if(mx > t){
            break;
        }
    }
    ans = min(ans, i - 1);
    printf("%d\n", ans);
}

int main() {
    int T;
    for(scanf("%d", &T); T; --T){
        read();
        work();
    }

    return 0;
}