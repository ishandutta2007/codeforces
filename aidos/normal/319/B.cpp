#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
string s;
int a[maxn];
int cnt[maxn];
int can(int x) {
    vector<int> d;
    for(int i = 0; i < n; i++) {
        cnt[i] = 0;
        for(;cnt[i] < x;) {
            if(d.size() == 0 || a[d.back()] < a[i]) break;
            cnt[i] = max(cnt[i] + 1, cnt[d.back()]);
            d.pop_back();
        }
        d.emplace_back(i);
    }
    for(int i = 1; i < d.size(); i++) {
        if(a[d[i-1]] > a[d[i]]) return false;
    }
    return true;
}
void solve(){
    cin >> n;
    for(int i=0; i < n; i++) {
        cin >> a[i];
        a[i] = n - a[i] + 1;
    }
    reverse(a, a + n);

    int l = 0, r = n;
    int res = -1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(can(mid)) {
            r = mid-1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    cout<<res<<'\n';
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