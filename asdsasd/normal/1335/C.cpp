#include <bits/stdc++.h>
using namespace std;

int cnt[220000];
void solve(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) cnt[i] = 0;
    int a;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    int type = 0;
    int max_ = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] > 0){
            type++;
            max_ = max(max_, cnt[i]);
        }
    }
    int ans = min(type, max_);
    if(type == max_) ans--;
    printf("%d\n", ans);
}

int main(void){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        solve();
    }
    
}