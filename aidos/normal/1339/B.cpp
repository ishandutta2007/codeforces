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
int n, m, k;
int a[maxn];
int b[maxn];
void solve() {
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(a, a + n);
    int mid = n/2;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) cout << a[(n-1)/2 - i/2] << " ";
        else cout << a[(n-1)/2 + i/2 + 1] << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}