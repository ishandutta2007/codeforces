#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    string s;
    cin >>n>> s;
    string ans = "";
    while(s.size() > 0 && s.back() =='1') {
        s.pop_back();
        ans += "1";
    }
    if(s.size() > 0) {
        reverse(s.begin(), s.end());
        while(s.size() > 0 && s.back() =='0') {
            s.pop_back();
            ans += "0";
        }
        if(s.size() > 0) ans += "0";
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
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