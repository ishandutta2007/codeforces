#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int prv[maxn], nxt[maxn];
int cnt[5][maxn];

void upd(int l, int r, int &bestl, int &bestr) {
    if(l + 1 > r - 1) return;
    if(cnt[2][r-1] - cnt[2][l] > 0){
        return;
    }
    if((cnt[0][r-1] + cnt[1][r-1] - cnt[0][l] - cnt[1][l]) % 2 > 0) return;
    if(bestl+1 > bestr-1) {
        bestl = l;
        bestr = r;
    } else if(cnt[0][r-1] - cnt[0][l] + cnt[4][r-1] - cnt[4][l] > cnt[0][bestr-1] - cnt[0][bestl] + cnt[4][bestr-1] - cnt[4][bestl]) {
        bestl = l;
        bestr = r;
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 0; j < 5; j++) {
            cnt[j][i] = cnt[j][i-1];
        }
        cnt[a[i] + 2][i]++;
    }

    int bestl = 0, bestr = 1;
    int last0 = 0;
    for(int i = 1; i <= n; i++) {
        upd(last0, i, bestl, bestr);
        if(a[i] == 0) last0 = i;
    }
    upd(last0, n+1, bestl, bestr);
    last0 = n+1;
    for(int i = n; i >= 1; i--) {
        upd(i, last0, bestl, bestr);
        if(a[i] == 0) last0 = i;
    }
    upd(0, last0, bestl, bestr);
    cout << bestl << " " << n - bestr + 1 << "\n";
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