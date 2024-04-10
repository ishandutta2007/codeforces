#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
string s;
int cnt[111];
vector<int> pr = {2, 3, 5, 7};
void solve() {
    cin >> n >> s;
    for(const char &c: s) {
        for(int j=2; j <= c-'0'; j++) {
            int x = j;
            for (int i = 0; i < pr.size(); i++) {
                while (x % pr[i] == 0) {
                    x/=pr[i];
                    cnt[i]++;
                }
            }
        }
    }
    string ans = "";
    for(int i = pr.size()-1; i >= 0; i--) {
        while(cnt[i] > 0) {
            ans += pr[i] + '0';
            for(int j = 2; j <= pr[i]; j++) {
                int x = j;
                for(int z = 0; z < pr.size(); z++) {
                    while(x % pr[z] == 0) {
                        x/=pr[z];
                        cnt[z]--;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
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