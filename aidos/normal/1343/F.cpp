#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
int n, m;
set<int> S[maxn], T[maxn];
int u[maxn];
int ans[maxn];
int last[maxn];
int TT;
bool rec(int pos) {
    if(pos > n) {
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(last[i] == last[j]) return false;
            }
        }
        return true;
    }
    int x = -1;
    int cc = 0;
    for(int i = 1; i < n; i++) {
        if(S[i].size() == 1) {
            x = *S[i].begin();
            cc++;
        }
    }
    if(cc != 1) return false;
    for(int i = 1; i < n; i++) {
        if(S[i].size() > 0 && u[i]) {
            if(S[i].count(x) == 0) return false;
        }
    }
    ans[pos] = x;
    TT++;
    for(int j = 1; j < n; j++) {
        if(S[j].count(x)) {
            u[j]++;
            S[j].erase(x);
            last[j] = TT;
        }
    }
    if(rec(pos+1)) return true;
    for(int j = 1; j < n; j++) {
        if(T[j].count(x)) {
            u[j]--;
            S[j].insert(x);
        }
    }

    return false;
}
void solve() {
    cin >> n;
    for(int i=1; i< n; i++) {
        S[i].clear();
        T[i].clear();
        u[i] = 0;
    }
    for(int i = 1; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            S[i].insert(x);
            T[i].insert(x);
        }
    }
    for(int i = 1; i <= n; i++) {
        TT = 1;
        for(int j = 1; j < n; j++) {
            last[j] = 0;
            if(S[j].count(i)) {
                u[j]++;
                S[j].erase(i);
                last[j] = TT;
            }
        }
        ans[1] = i;
        if(rec(2)) {
            for(int j=1; j <= n; j++) {
                cout << ans[j] << " ";
            }
            cout << "\n";
            return;
        }
        for(int j = 1; j < n; j++) {
            if(T[j].count(i)) {
                u[j]--;
                S[j].insert(i);
            }
            assert(u[j] == 0);
        }
    }
    cout << -1 << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}