#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;

int n, k;
int a[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 0;  i < n; i++) cin >> a[i];
    int f1 = 0, f2 = 0;
    a[n] = a[n + 1] = -inf;
    for(int i = 0; i < n; i++) {
        if(a[i] == k) f1 = 1;
        if(a[i] >= k && a[i + 1] >= k) f2 = 1;
        if(a[i] >= k && a[i + 2] >= k) f2 = 1;
    }
    if(!f1 || (!f2 && n > 1)) {
        cout << "no\n";
    }else {
        cout << "yes\n";
    }
}


int main() {
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}