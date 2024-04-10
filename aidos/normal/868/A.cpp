#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
string a[maxn], s;
void solve() {
    cin >> s >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == s) {
            cout << "YES\n";
            return;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][1] == s[0] && a[j][0] == s[1]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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