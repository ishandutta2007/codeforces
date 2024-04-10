#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    string s;
    cin >> s;
    if(s.size() % 2==1 || s[0] == ')' || s.back() == '(') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

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