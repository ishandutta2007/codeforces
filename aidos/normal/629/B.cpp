#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2020 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
int b[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        int l, r;
        cin >> s >> l >> r;
        if(s[0] == 'F') {
            for(int j = l; j <= r; j++) a[j]++;
        } else {
            for(int j = l; j <= r; j++) b[j]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < maxn; i++) ans = max(ans, min(a[i], b[i]));
    cout << 2*ans << "\n";
}


int main() {
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