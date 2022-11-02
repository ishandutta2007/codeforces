#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
typedef long long ll;
int n, q;
string s;
int m[1<<5][1<<5];
string x[] = {"a", "b", "c", "ab", "bc"};
vector< pair<int ,int> > d;
bool can(string x, string y) {
    int j = 0;
    for(int i = 0; i < x.size() && j < y.size(); i++) {
        if(x[i] == y[j]) j++;
    }
    return j == y.size();
}
int get_mask(int mask1, int mask2) {
    int res = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(mask1 & (1<<i)) {
                if(mask2 & (1<<j)) {
                    if(can(x[i] + x[j], "abc")) return -1;
                    for(int k = 0; k < 5; k++) {
                        if(can(x[i] + x[j], x[k])) res |= 1<<k;
                    }
                }
            }
        }
    }
    return res;
}
int t[4 * maxn][1<<5];
void build(int v, int l, int r) {
    for(int i = 0; i < (1<<5); i++){
        t[v][i] = 1<<29;
    }
    if(l == r) {

        for(int i = 0; i < 3; i++) {
            if(s[l] == i + 'a') {
                t[v][1<<i] = 0;
            } else {
                t[v][1<<i] = 1;
            }
        }
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        for(auto [mask1, mask2]: d){
            int nxt = m[mask1][mask2];
            if(nxt != -1) {
                t[v][nxt] = min(t[v][nxt], t[v * 2][mask1] + t[v * 2 + 1][mask2]);
            }
        }
    }
}
void upd(int v, int l, int r, int pos, int val) {
    for(int i = 0; i < (1<<5); i++){
        t[v][i] = 1<<29;
    }
    if(l == r) {

        for(int i = 0; i < 3; i++) {
            if(val == i) {
                t[v][1<<i] = 0;
            } else {
                t[v][1<<i] = 1;
            }
        }
    } else {
        int mid = (l + r)/2;
        if(pos <= mid) {
            upd(v * 2, l, mid, pos, val);
        } else {
            upd(v * 2 + 1, mid + 1, r, pos, val);
        }
        for(auto [mask1, mask2]: d){
                int nxt = m[mask1][mask2];
                if(nxt != -1) {
                    t[v][nxt] = min(t[v][nxt], t[v * 2][mask1] + t[v * 2 + 1][mask2]);
                }
            }

    }
}
void solve(){
    cin >> n >> q;
    for(int mask = 0; mask < (1<<5); mask++) {
        for(int mask2 = 0; mask2 < (1<<5); mask2++) {
            m[mask][mask2] = get_mask(mask, mask2);
            if(m[mask][mask2] != -1) d.push_back({mask, mask2});
        }
    }
    cin >> s;
    build(1, 0, n-1);
    for(int i = 0; i < q; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        upd(1, 0, n-1, pos-1, c - 'a');
        cout << *min_element(t[1], t[1] + (1<<5)) << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}