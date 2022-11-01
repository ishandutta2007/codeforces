#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int a[3] = {0,0,0};
    for(char c : s) a[c-'A']++;
    if(a[1]==a[0]+a[2]) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int t=0;t<T;t++) solve();
}