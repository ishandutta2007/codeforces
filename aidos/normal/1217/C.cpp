#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;
string s;
int p[maxn];
void solve() {
    int last = -1;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {

        if(s[i] == '1') {
            int cur = 0;
            for(int j = 0; j < 20 && j + i < s.size(); j++) {
                cur = cur * 2 + s[j + i] - '0';
                int l = j + 1;
                int r = j + i - last;
                if(cur >= l && cur <= r) ans++;
            }
            last = i;
        }
    }
    cout << ans << "\n";
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