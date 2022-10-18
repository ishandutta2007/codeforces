#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int a[400000];

int brute_sol(vector<int> b) {
    int n = b.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0, mx = 0;
        int j = i;
        for(; j < n; j++) {
            sum += b[j];
            mx = max(mx, b[j]);
            if(sum - mx >= mx && sum % 2 == 0) {
                ans++;
            }
        }
    }
    return ans;
}

int my_sol(vector<int> b) {
    int n = b.size();
    const int logn = 70;
    int ans = 0;
    int pref[n + 1];
    pref[0] = 1;
    int sm = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0, mx = 0;
        int j = i;
        for(; j < i + logn && j < n; j++) {
            sum += b[j];
            mx = max(mx, b[j]);
            if(sum - mx >= mx && sum % 2 == 0) {
                ans++;
            }
        }
        
        sm += b[i];
        pref[i + 1] = pref[i] + (sm % 2 == 0);
        if(i >= logn) {
            ans += sm % 2 == 0 ? pref[i - logn] : (i - logn + 1) - pref[i - logn];
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = __builtin_popcountll(a[i]);
    }
    cout << my_sol(b) << endl;
}