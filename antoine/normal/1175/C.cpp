#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int a[(int)2e5 + 9];

int f() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int ans1=  -1, ans2 = numeric_limits<int>::max();

    for(int i = 0; i + k < n; ++i) {
        int c1 = (a[i+k] + a[i]) / 2;
        int c2 = a[i+k] - a[i];
        if(c2 < ans2) {
            ans2 = c2;
            ans1 = c1;
        }
    }
    return ans1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        cout << f() << '\n';
    return 0;
}