#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    char s;
    int l = k;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == '0'){
            l++;
        }
        else{
            l-= k;
            ans += l / (1 + k);
            l = 0;
        }
    }
    ans += l / (1 + k);
    printf("%d\n", ans);
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
}