#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
string s;
void solve() {
    cin >> n >> k >> s;
    vector<int> cnt(3, 0);
    for(int i = 0; i < k; i++) {
        int x = 0;
        for(int j = i; j < n; j += k) {
            if(s[j] == '?') continue;
            if(s[j] == '1') x |= 2;
            else x |= 1;
        }
        if(__builtin_popcount(x) > 1) {
            cout << "NO\n";
            return;
        }
        cnt[x]++;
    }
    if(cnt[0] + cnt[1] >= cnt[2] && cnt[2] + cnt[0] >= cnt[1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}