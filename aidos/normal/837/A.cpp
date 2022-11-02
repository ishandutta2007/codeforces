#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
string s;
void solve() {
    cin >> n;
    int ans = 0;
    while(cin >> s) {
        int cnt = 0;
        for(const char &c: s) {
            if(isupper(c)) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
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