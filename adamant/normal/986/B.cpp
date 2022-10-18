#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1e5 + 42;

vector<int> cycles(vector<int> p) {
    int n = p.size();
    vector<int> used(n);
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            int cnt = 0;
            int j = i;
            while(!used[j]) {
                used[j] = 1;
                j = p[j];
                cnt++;
            }
            ans.push_back(cnt);
        }
    }
    sort(begin(ans), end(ans));
    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    auto lol = cycles(p);
    int parity = 0;
    for(auto it: lol) {
        parity ^= (it - 1) % 2;
    }
    cout << (parity == (n % 2) ? "Petr" : "Um_nik") << endl;
    
    return 0;
}