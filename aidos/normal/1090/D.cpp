#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
set<int> s[maxn];
void solve(){
    cin>> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x>> y;
        s[x].insert(y);
        s[y].insert(x);
    }
    for(int i = 1; i <= n; i++) {
        if(s[i].size() == n-1) continue;
        int j = i+1;
        while(s[i].count(j)) j++;
        cout << "YES\n";
        for(int k = 1; k <= n; k++) {
            if(k == i) {
                cout << n - 1 << " ";
            } else if(k == j) {
                cout << n << " ";
            } else if(k < i) {
                cout << k << " ";
            } else if(k < j) {
                cout << k - 1 << " ";
            } else {
                cout << k - 2 << " ";
            }
        }
        cout << "\n";
        for(int k = 1; k <= n; k++) {
            if(k == i) {
                cout << n - 1 << " ";
            } else if(k == j) {
                cout << n - 1 << " ";
            } else if(k < i) {
                cout << k << " ";
            } else if(k < j) {
                cout << k - 1 << " ";
            } else {
                cout << k - 2 << " ";
            }
        }
        cout << "\n";
        return;
    }
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}