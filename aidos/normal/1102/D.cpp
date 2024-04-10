#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
string s;
int cnt[3];
void solve() {
    cin >> n >> s;
    for(int i = 0 ; i < n; i++) cnt[s[i]-'0']++;
    for(int i = 0; i < 3; i++) {
        if(cnt[i] >= n/3) continue;
        for(int j = 0; j < n; j++) {
            if(cnt[s[j] - '0'] > n/3 && cnt[i] < n/3 && s[j] - '0' > i) {
                cnt[s[j] - '0']--;
                cnt[i]++;
                s[j] = '0' + i;
            }
        }
    }
    for(int i = 2; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(cnt[s[j] - '0'] > n/3 && cnt[i] < n/3) {
                cnt[s[j] - '0']--;
                cnt[i]++;
                s[j] = '0' + i;
            }
        }
    }
    cout << s << "\n";
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