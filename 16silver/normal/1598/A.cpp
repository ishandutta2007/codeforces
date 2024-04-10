#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    for(int i=0;i<n;i++) if(s[0][i] == '1' && s[1][i] == '1'){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}