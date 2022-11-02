#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
char a[maxn];
int cnt[maxn];
int c[maxn];
void solve(){
    string a;
    cin >> a;
    n = a.size();
    k = 2;
    for(int i = 0; i < 26; i++) {
        cnt[i] = k;
    }
    for(int i = 0; i < n; i++) {
        c[i] = 0;
    }
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; i++) {

        int t = a[i] - 'a';
        if(cnt[t] > 0) {
            pos.push_back({t, i});
            cnt[t]--;
        }
    }
    sort(pos.begin(), pos.end());

    int d = pos.size()/k;
    //d *= k;
    cout << d << "\n";
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}