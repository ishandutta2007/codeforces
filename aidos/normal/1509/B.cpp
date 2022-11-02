#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    string s;
    cin >> n >> s;
    vector<int> a, b, c;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'M') b.push_back(i);
        else if(a.size() < n/3) a.push_back(i);
        else c.push_back(i);
    }
    if(b.size() != n/3) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < n/3; i++) {
        if(a[i] < b[i] && b[i] < c[i]) {
            continue;
        }
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