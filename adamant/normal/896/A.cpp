#include <bits/stdc++.h>

using namespace std;
#define int int64_t

#define all(x) begin(x), end(x)

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string f1 = "What are you doing while sending \"";
string f2 = "\"? Are you busy? Will you send \"";
string f3 = "\"?";


const int inf = int(1e18) + 42, maxn = 1e5 + 42;

int ln[maxn];

int len(int n) {
    if(n == 0) {
        return f0.size();
    }
    if(!ln[n]) {
        ln[n] = min(inf, int(f1.size()) + int(f2.size()) + int(f3.size()) + 2 * len(n - 1));
    }
    return ln[n];
}

char recover(int n, int k) {
    if(n == 0) {
        return k > f0.size() ? '.' : f0[k - 1];
    } else {
        if(k <= f1.size()) {
            return f1[k - 1];
        } else if(k <= f1.size() + len(n - 1)) {
            return recover(n - 1, k - f1.size());
        } else if(k <= f1.size() + len(n - 1) + f2.size()) {
            return f2[k - f1.size() - len(n - 1) - 1];
        } else if(k <= f1.size() + len(n - 1) + f2.size() + len(n - 1)) {
            return recover(n - 1, k - f1.size() - len(n - 1) - f2.size());
        } else if(k <= len(n)) {
            return f3[k - f1.size() - len(n - 1) - f2.size() - len(n - 1) - 1];
        } else {
            return '.';
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        cout << recover(n, k);
    }
    return 0;
}