#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
void solve(int st) {}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A[4];
    int B[4];
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> A[i];
        sum += A[i];
    }
    vector<int> res;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            B[k] = A[k];
        }
        int cur = i;
        if(B[cur] == 0)continue;
        B[cur]--;
        res.push_back(cur);
        while (true) {
            if (cur == 2) {
                if (B[cur + 1] > 0) {
                    cur++;
                } else {
                    cur--;
                }
            }else if (cur == 1) {
                if (B[cur - 1] > 0) {
                    cur--;
                } else {
                    cur++;
                }
            }
            else if (cur == 0) cur++;
            else if (cur == 3) cur--;
            B[cur]--;
            if (B[cur] < 0) break;
            res.push_back(cur);
        }
        if ((int)res.size() < sum) {
            res.clear();
        }

        if (res.size() > 0) break;
    }
    if (res.size() > 0) {
        cout << "YES" << endl;
        for (int i = 0; i < res.size(); i++) {
            if (i > 0) cout << " ";
            cout << res[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}