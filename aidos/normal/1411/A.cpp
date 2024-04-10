#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    string s;
    cin >> n >> s;
    int pos = n-1;
    while(pos >= 0 && s[pos] == ')') pos--;

    if(pos + 1 < n - pos - 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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