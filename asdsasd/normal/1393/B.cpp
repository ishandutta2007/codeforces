#include <bits/stdc++.h>
using namespace std;

int cnt[100100];

void solve(){
    for(int i = 0; i < 100100; i++) cnt[0] = 0;
    int n;
    scanf("%d", &n);
    int a;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    int q;
    scanf("%d", &q);
    char ope;
    int x;
    int four_cnt = 0;
    int two_cnt = 0;
    for(auto c: cnt){
        four_cnt += c / 4;
        two_cnt += c / 2;
    }
    
    while(q--){
        cin >> ope >> x;
        if(ope == '+'){
            cnt[x]++;
            if(cnt[x] % 4 == 0) four_cnt++;
            if(cnt[x] % 2 == 0) two_cnt++;
        }
        else{
            if(cnt[x] % 4 == 0) four_cnt--;
            if(cnt[x] % 2 == 0) two_cnt--;
            cnt[x]--;
        }
        if(four_cnt >= 1 && two_cnt >= 4) printf("YES\n");
        else printf("NO\n");
    }
    
}

int main(void){
    solve();
}