#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);

int a[3];
void solve() {
    int x, y;
    cin >> x >> y;
    for(int i = 0; i < 3; i++) a[i] = y;
    for(int j = 0; ; j++) {
        int cur = j % 3;
        if(a[cur] >= x) {
            cout << j << "\n";
            return;
        }
        a[cur] = a[(cur+1) % 3] + a[(cur + 2) % 3] - 1;
    }

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