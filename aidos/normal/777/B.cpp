#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
string s, t;
int cnta[11], cntb[11];
void solve() {
    cin >> n >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i = 0; i < n; i++) {
        cnta[s[i] - '0']++;
        cntb[t[i] - '0']++;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 9; i >= 0; i--) {
        while(cntb[i] > 0) {
            int j = i;
            while(j >= 0 && cnta[j] == 0) {
                j--;
            }
            cntb[i]--;
            if(j == -1) cnt1++;
            else cnta[j]--;
        }
    }
    for(int i = 0, j = 0; j < s.size() && i < t.size(); j++) {
        while(i < t.size() && t[i] <= s[j]) i++;
        if(i == t.size()) break;
        i++;
        cnt2++;
    }
    cout << cnt1 << "\n";
    cout << cnt2 << "\n";
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