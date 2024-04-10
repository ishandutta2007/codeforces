#include <bits/stdc++.h>
using namespace std;

int cnt[100100];

void solve(){
    int n;
    scanf("%d", &n);
    int a;
    for(int i = 1; i <= n; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    int max_ = 0;
    int max_cnt = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == max_) max_cnt++;
        else if(cnt[i] > max_){
            max_ = cnt[i];
            max_cnt = 1;
        }
    }
    n -= max_cnt;
    max_--;
    int ans = max(0, n / max_ - 1);
    printf("%d\n", ans);
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}