#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    string s;
    cin >> s;
    map<char, int> pos;
    for(int i = 0; i < s.size(); i++) {
        pos[s[i]] = i;
    }
    if(pos['b'] > pos['B'] || pos['r'] > pos['R'] || pos['g'] > pos['G']) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}