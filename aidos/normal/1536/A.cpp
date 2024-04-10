#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    set<ll> s;
    int bad = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
        if(x < 0) {
            bad = 1;
        }
    }
    if(bad) {
        cout << "NO\n";
        return;
    }
    while(s.size() <= 300) {
        vector<int> v(s.begin(), s.end());
        int cnt = 0;
        for(int i = 0; i < v.size(); i++) {
            for(int j = i + 1; j < v.size(); j++) {
                if(s.count(v[j] - v[i])) {
                    continue;
                }
                ++cnt;
                s.insert(v[j] - v[i]);
            }
        }
        if(cnt ==0) break;
    }
    cout << "YES\n";
    cout << s.size() << "\n";
    for(int x: s) {
        cout << x << " ";
    }
    cout<<"\n";
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