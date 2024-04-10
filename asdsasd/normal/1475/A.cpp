#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    while(n > 1){
        if(n % 2 == 1){
            printf("YES\n");
            return;
        }
        n /= 2;
    }
    printf("NO\n");
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
}