#include <bits/stdc++.h>
using namespace std;

void solve(){
    string S;
    cin >> S;
    int a = 0;
    int b = 0;
    int c = 0;
    for(auto s: S){
        if(s == 'A') a++;
        else if(s == 'B') b++;
        else c++;
    }
    if(a + c == b) cout << "YES\n";
    else cout << "NO\n";
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}