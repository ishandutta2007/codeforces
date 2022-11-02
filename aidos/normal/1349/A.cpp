#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;

int n;

set<int> s;
int a[maxn];
void calc(int x) {
    for(int i = 2; i <= x; i++) {
        if(x % i == 0) {
            s.insert(i);
            while(x % i == 0) x/=i;
        }
    }
}
int cnt[105];
int get(int p) {
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
        int c = 0;
        while(a[i] % p == 0) {
            a[i] /= p;
            c++;
        }
        cnt[c]++;
    }
    int cur = 0;
    for(int i = 0; i < 100; i++) {
        cur+=cnt[i];
        if(cur >= 2) return i;
    }

    return 100;
}
void solve() {
    cin >> n;
    for(int i = 0;  i < n; i++) cin >> a[i];
    calc(a[0]);
    calc(a[1]);
    ll ans = 1;
    for(const int &pr: s) {
        int mx = get(pr);
        for(int i = 0; i < mx; i++) ans *= pr;
    }
    cout << ans << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}