#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    string s;
    cin >> s;
    string d[] = {"00", "52", "05", "57"};
    reverse(s.begin(), s.end());
    int t = s.size();
    for(auto x: d) {
        int cur = 0;
        int ans=0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == x[cur]) {
                cur++;
            } else {
                ans++;
            }
            if(cur == 2) break;
        }
        if(cur == 2) t = min(t, ans);
    }
    cout << t << "\n";
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