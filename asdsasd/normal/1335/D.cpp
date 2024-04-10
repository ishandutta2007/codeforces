#include <bits/stdc++.h>
using namespace std;

int cnt[220000];
void solve(){
    string S;
    for(int i = 0; i < 9; i++){
        cin >> S;
        for(auto s:S){
            if(s == '1') printf("2");
            else printf("%c", s);
        }
        printf("\n");
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        solve();
    }
    
}