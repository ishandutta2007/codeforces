#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    multiset<string> lst;
    for(int i = 0; i < n; i++){
        string S;
        cin >> S;
        lst.insert(S);
        for(int pos = 0; pos < m; pos++){
            char bef = S[pos];
            for(char s = 'a'; s <= 'z'; s++){
                if(s == bef) continue;
                S[pos] = s;
                lst.insert(S);
            S[pos] = bef;
            }
        }
    }
    for(auto p: lst){
        if(lst.count(p) == n){
            cout << p << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}