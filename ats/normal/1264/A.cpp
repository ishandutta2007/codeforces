#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int a = 0;
        int b = 0;
        int c = 0;
        vector<int> sum;
        for (int i = 0; i < N; i++) {
            if (i == 0 || A[i] != A[i - 1]) {
                sum.push_back(0);
            }
            sum.back()++;
        }
        // for (int i = 0; i < sum.size(); i++) {
        //     cerr << sum[i] << " ";
        // }
        // cerr << endl;
        a = sum[0];
        int cur;
        for (cur = 1; cur < sum.size(); cur++) {
            b += sum[cur];
            if (a < b) break;
        }
        cur++;
        for (; cur < sum.size(); cur++) {
            if(2 * (a + b + c + sum[cur]) > N)break;
            c += sum[cur];
        }
        if(a >= b || a >= c){
            a = b = c = 0;
        }
        cout << a <<" " << b << " " << c << "\n";
    }
    return 0;
}