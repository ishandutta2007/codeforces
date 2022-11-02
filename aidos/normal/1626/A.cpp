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
    sort(a.begin(), a.end());
    cout << a << "\n";
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