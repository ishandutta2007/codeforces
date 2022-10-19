#include <bits/stdc++.h>
using namespace std;

void solve(){
    string S;
    cin >> S;
    int n = S.size();
    int ind = -1;
    for(int i = 0; i < n; i++){
        if(S[i] == 'a'){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        printf("NO\n");
        return;
    }
    char s = 'b';
    int l = ind - 1;
    int r = ind + 1;
    while(1){
        if(l >= 0 && S[l] == s){
            s += 1;
            l -= 1;
        }
        else if(r < n && S[r] == s){
            s += 1;
            r += 1;
        }
        else{
            break;
        }
    }
    if(l == -1 && r == n) printf("YES\n");
    else printf("NO\n");
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}