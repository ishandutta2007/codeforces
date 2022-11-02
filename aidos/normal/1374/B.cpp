#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
void solve() {
    cin >> n;
    int a = 0, b = 0;
    while(n % 6 == 0) {
        n/=6;
        a++;
    }
    while(n % 3 == 0) {
        a+=2;
        n/=3;
    }
    if(n != 1) {
        cout << -1<<"\n";
    } else {
        cout << a << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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