#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define filename ""
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, k;
string s;
void solve() {
    cin >> s;
    int n = s.size();
    int j = n - 1;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(s[i] == ')') continue;
        while(j > i && s[j] == '(') j--;
        if(j > i) {
            ans.emplace_back(i);
            ans.emplace_back(j);
            j--;
        }
    }
    sort(ans.begin(), ans.end());

    if(ans.size() > 0) {
        cout << 1 << "\n" << ans.size() << "\n";
        for (int &v: ans) cout << v + 1 << " ";
    } else {
        cout << 0 << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}