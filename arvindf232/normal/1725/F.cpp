#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int qu[1<<5];
void solve(){
    int n;
    scanf("%d", &n);
    pair <int,int> a[n+1];
    for (int i=1; i<=n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    qu[0]=n;
    int cur=0;
    for (int q=1; q<30; q++){
        if (q > 15) {
            map<int, int> mp;
            for (int i = 1; i <= n; i++) {
                int xx = a[i].x & ((1 << q) - 1), yy = a[i].y & ((1 << q) - 1);
                if (a[i].y - a[i].x + 1 >= (1 << q)) {
                    mp[0]++;
                } else if (xx > yy) {
                    mp[xx]++;
                    mp[0]++;
                    mp[yy + 1]--;
                } else {
                    mp[xx]++;
                    mp[yy + 1]--;
                }
            }
            cur = 0;
            map<int, int>::iterator it = mp.begin();
            while (it != mp.end()) {
                cur += it->second;
                qu[q] = max(qu[q], cur);
                ++it;
            }
        } else {
            int mp[(1 << q) + 1];
            for (int i = 0; i <= (1 << q); i++) mp[i] = 0;
            for (int i = 1; i <= n; i++) {
                int xx = a[i].x & ((1 << q) - 1), yy = a[i].y & ((1 << q) - 1);
                if (a[i].y - a[i].x + 1 >= (1 << q)) {
                    mp[0]++;
                } else if (xx > yy) {
                    mp[xx]++;
                    mp[0]++;
                    mp[yy + 1]--;
                } else {
                    mp[xx]++;
                    mp[yy + 1]--;
                }
            }
            cur = 0;
            for (int i = 0; i <= (1 << q); i++) {
                cur += mp[i];
                qu[q] = max(qu[q], cur);
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q--){
        int t;
        scanf("%d", &t);
        for (int j=0; ; j++){
            if (t&(1<<j)){
                printf("%d\n", qu[j]);
                break;
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}