#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
int a[maxn];
int b[maxn];
int B[maxn];
void calc(int c) {
    for(int i = 0; i < n; i++) {
        b[i] = a[i];
        B[i] = b[i];
    }
    for(int i = 0;i < c; i++) {
        int cur = -1;
        for(int j = i; j < n; j++) {
            if(b[j] >= (1<<c)) break;
            if(b[j] & (1<<i)) cur = j;
        }
        if(cur == -1) return;
        swap(b[cur], b[i]);
        swap(B[cur], B[i]);
        for(int j = i+1; j < n; j++) {
            if(i == j) continue;
            if(b[j] & (1<<i)) b[j] ^= b[i];
        }
    }
    cout << c << "\n";
    for(int i = 0; i < (1<<c); i++) {
        int x = i^(i>>1);
        int res = 0;
        for(int j = 0; j < c; j++)
            if(x & (1<<j)) res ^= B[j];
        cout << res << " ";
    }
    cout << "\n";
    exit(0);
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 18; i >= 0; i--) {
        calc(i);
    }
}


int main() {
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