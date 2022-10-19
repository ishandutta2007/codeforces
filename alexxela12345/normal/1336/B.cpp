#ifndef DEBUG
//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
typedef long long ll;
typedef long double ldb;

int sq(int a) {
    return a * a;
}

int calc(int a, int b, int c) {
    return sq(a - b) + sq(b - c) + sq(a - c);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> aa(a), bb(b), cc(c);
        for (int i = 0; i  < a; i++) {
            cin >> aa[i];
        }
        for (int i = 0; i < b; i++) {
            cin >> bb[i];
        }
        for (int i = 0; i < c; i++) {
            cin >> cc[i];
        }
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        sort(cc.begin(), cc.end());
        vector<int> arr2 = {0, 1, 2};
        int best_ans = LLONG_MAX;
        do {
            vector<vector<int>> arr(3);
            for (int i = 0; i < 3; i++) {
                if (arr2[i] == 0) {
                    arr[i] = aa;
                } else if (arr2[i] == 1) {
                    arr[i] = bb;
                } else {
                    arr[i] = cc;
                }
            }
            int ind1 = 0;
            int ind2 = 0;
            for (int i = 0; i < arr[0].size(); i++) {
                while (ind1 < arr[1].size() && arr[0][i] > arr[1][ind1]) {
                    ind1++;
                }
                if (ind1 == arr[1].size())
                    break;
                while (ind2 < arr[2].size() && arr[1][ind1] > arr[2][ind2]) {
                    ind2++;
                }
                while (ind1 + 1 < arr[1].size() && calc(arr[0][i], arr[1][ind1], arr[2][ind2]) >= calc(arr[0][i], arr[1][ind1 + 1], arr[2][ind2]) && arr[1][ind1 + 1] <= arr[2][ind2]) {
                    ind1++;
                }
                if (ind2 == arr[2].size())
                    break;
                best_ans = min(best_ans, calc(arr[0][i], arr[1][ind1], arr[2][ind2]));
            }
        } while (next_permutation(arr2.begin(), arr2.end()));
        cout << best_ans << endl;
    }
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/