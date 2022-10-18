#include <bits/stdc++.h>

using namespace std;

bool check_inv(vector<int> a, vector<int> b) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(b[i] < 0 || b[i] > n) {
            return false;
        }
        if(a[b[i]] != i) {
            return false;
        }
    }
    return true;
}

int xr[2][5001];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "? " << 0 << " " << i << endl;
        cin >> xr[0][i];
    }
    for(int i = 0; i < n; i++) {
        cout << "? " << i << " " << 0 << endl;
        cin >> xr[1][i];
    }
    vector<int> ans;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        vector<int> a(n), b(n);
        a[0] = i;
        for(int j = 0; j < n; j++) {
            b[j] = a[0] ^ xr[0][j];
        }
        for(int j = 0; j < n; j++) {
            a[j] = b[0] ^ xr[1][j];
        }
        if(check_inv(a, b)) {
            cnt++;
            ans = a;
        }
    }
    cout << "!\n" << cnt << "\n";
    for(auto it: ans) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}