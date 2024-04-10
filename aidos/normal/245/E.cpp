#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 100;
string s;
void solve() {
    cin >> s;
    int bal = 0;
    int need = 0;
    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+') bal++;
        else bal--;
        if(need > bal) need = bal;
        cur = max(cur, bal);
    }
    cout << cur-need << "\n";
}
int main(){
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d:\n", i);
        solve();
    }

}