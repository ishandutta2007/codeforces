//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//using ld = double;
//using pii = pair<int, int>;
//using vi = vector<int>;
//#define sz(a) (int)((a).size())
//#define all(a) (a).begin(), (a).end()
//#define pb push_back
//#define x first
//#define y second
//const int maxn = 1e6, mod = 1e9 + 7;
//
//int n, m, q, cnt[1 << 12], w[12], mask;
//vector<int> ans[1 << 12];
//
//int get() {
//    int x = 0;
//    for(int i = 0; i < n; i++) {
//        char z; cin >> z; x = x * 2 + z - '0';
//    }
//    return x;
//}
//void gen(int x, int i, int sum) {
//    if(sum > 100) return;
//    //if(x == 0 && i == n) cout << "! " << mask << ' ' << cnt[mask] << ' ' << sum << endl;
//    if(i == n) ans[x][sum] += cnt[mask];
//    else {
//        bool bit = (x & (1 << i)) != 0;
//        mask *= 2;
//        if(!bit) sum += w[i];
//        gen(x, i + 1, sum);
//        if(!bit) sum -= w[i];
//        mask++;
//        if(bit) sum += w[i];
//        gen(x, i + 1, sum);
//        if(bit) sum -= w[i];
//        mask--;
//        mask >>= 1;
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    //freopen("in.txt", "r", stdin);
//    cin >> n >> m >> q;
//    for(int i = 0; i < n; i++) cin >> w[i];
//    for(int i = 0; i < m; i++) {
//        cnt[get()]++;
//    }
//    for(int ma = 0; ma < (1 << n); ma++) {
//        ans[ma].resize(101, 0);
//        gen(ma, 0, 0);
//        for(int i = 1; i <= 100; i++) ans[ma][i] += ans[ma][i - 1];
//    }
//    while(q--) {
//        int x = get(), k; cin >> k; cout << ans[x][k] << '\n';
//    }
//}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
const int maxn = 1e6, mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    int opt = n + 1, len = 1;
    for(int i = 2; i <= n; i++)
        if(i + (n + i - 1) / i < opt) {
            opt = i + (n + i - 1) / i;
            len = i;
        }
    vi a(2 * n);
    for(int i = 0; i < (n + len - 1) / len; i++) {
        a[i * len] = max(1, n - (i + 1) * len + 1);
        for(int j = 1; j < len; j++) a[i * len + j] = a[i * len + j - 1] + 1;
    }
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
}