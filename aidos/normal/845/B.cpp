#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
string s;
void solve() {
    cin >> s;
    int ans = inf;
    for(int i = 0; i < 1e6; i++) {
        int x = i;
        int sum = 0;
        int cnt = 0;
        for(int j = 0; j < 6; j++) {
            int cur = x % 10;
            x/=10;
            if(j < 3) sum += cur;
            else sum -= cur;
            if(s[j] != cur + '0') cnt++;
        }
        if(sum == 0)ans = min(ans, cnt);
    }
    cout<<ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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