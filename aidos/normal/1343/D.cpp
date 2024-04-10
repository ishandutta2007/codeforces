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
int n, k;
int a[maxn];
int cnt[2 * maxn];
void solve() {
    cin >> n >> k;
    vector<pii> b;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n/2; i++) {
        int x = a[i], y = a[n-i-1];
        if(x > y) swap(x, y);
        cnt[2] += 2;
        cnt[x+1]--;
        cnt[x+y]--;
        cnt[x+y+1]++;
        cnt[k+y+1]++;
    }
    int ans = inf;
    for(int i = 2; i <= 2 * k; i++) {
        cnt[i] += cnt[i-1];
        ans = min(ans, cnt[i]);
    }
    for(int i = 0; i <= 2 * k + 10; i++){
        cnt[i] = 0;
    }
    cout << ans << "\n";


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