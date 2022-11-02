#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
string s;
string t;
int p[maxn];
int u[maxn];
int ok(int len) {
    for(int i = 0; i < n; i++) u[i] = false;
    for(int i = 0; i < len; i++) u[p[i]] = true;
    int pos = 0;
    for(int i = 0; i < n && pos < t.size(); i++) {
        if(u[i]) continue;
        if(s[i] == t[pos]) pos++;
    }
    return pos == t.size();
}
void solve() {
    cin >> s >> t;
    n = s.size();
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    int l = 0, r = n;
    int res = 0;
    while(l <= r) {
        int mid = (l + r)/2;
        if(ok(mid)) {
            res = mid;
            l = mid+1;
        }else {
            r = mid-1;
        }
    }
    cout << res << "\n";
}

int main() {
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}


#pragma clang diagnostic pop