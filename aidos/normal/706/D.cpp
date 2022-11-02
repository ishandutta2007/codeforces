#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
int k;
string s;
int cur = 1;
int sz[30 * maxn];
int nxt[30 * maxn][2];
bool get_bit(int x, int i) {
    return x & (1<<i);
}
void add(int x) {
    int v = 0;
    for(int i = 29; i >= 0; i--) {
        int bit = get_bit(x, i);
        if(nxt[v][bit] == 0) nxt[v][bit] = cur++;
        v = nxt[v][bit];
        sz[v]++;
    }
}
void del(int x) {
    int v = 0;
    for(int i = 29; i >= 0; i--) {
        int bit = get_bit(x, i);
        if(nxt[v][bit] == 0) nxt[v][bit] = cur++;
        v = nxt[v][bit];
        sz[v]--;
    }
}
int ask(int x) {
    int ans = 0;
    int v = 0;
    for(int i = 29; i >= 0; i--) {
        int bit = !get_bit(x, i);
        if(nxt[v][bit] == 0 || sz[nxt[v][bit]] == 0) {
            v = nxt[v][!bit];
        } else {
            v = nxt[v][bit];
            ans ^= (1<<i);
        }
    }
    return ans;
}
void solve() {
    cin >> n;
    add(0);
    for(int i = 0; i < n; i++) {
        cin >> s >> k;
        if(s == "+") add(k);
        else if(s == "-") del(k);
        else cout << ask(k) << "\n";
    }
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}