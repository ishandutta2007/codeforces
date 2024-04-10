#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int d = abs(a - b);
    int max_ = max(a, max(b, c));
    if(max_ > d * 2){
        cout << "-1\n";
        return;
    }
    if(c > d) cout << c - d << "\n";
    else cout << c + d << "\n";
    
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}