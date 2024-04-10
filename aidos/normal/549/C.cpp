#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, k;
int cnt[2];
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 2]++;
    }
    if(k == n) {
        if(cnt[1] % 2 == 1) {
            cout << "Stannis\n";
        }else {
            cout << "Daenerys\n";
        }
        return;
    }
    if((n - k) % 2) {
        if(k % 2 == 0) {
            if((n-k)/2>=cnt[0] || (n-k)/2 >= cnt[1]) {
                cout << "Daenerys\n";
            } else {
                cout << "Stannis\n";
            }
        } else {
            if((n-k)/2 >= cnt[1]) {
                cout << "Daenerys\n";
            } else {
                cout << "Stannis\n";
            }
        }
        return;
    }
    if(k % 2 == 1 && (n-k + 1)/2 >= cnt[0]) {
        cout << "Stannis\n";
        return;
    }
    cout << "Daenerys\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}