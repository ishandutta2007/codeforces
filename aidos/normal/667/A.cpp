#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e3 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
double d, h, v, e;
void solve() {
    cin >> d >> h >> v >> e;
    double area = d * d * pi/4;
    v/=area;
    if(v - e < 1e-9) cout << "NO\n";
    else cout << "YES\n" << h/(v-e) << "\n";
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