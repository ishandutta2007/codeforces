#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> c, d;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            d.push_back(i+1);
        } else {
            c.push_back(i+1);
        }
    }
    if(d.size() >= n/2) {
        cout << d.size() << "\n";
        for(int x: d) {
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }
    if(c.size() % 2 == 1) {
        c.pop_back();
    }
    cout << c.size() << "\n";
    for(int x: c) {
        cout << 1 << " ";
    }
    cout << "\n";
    return;
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