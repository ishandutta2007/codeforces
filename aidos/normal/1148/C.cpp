#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int p[maxn];
int pos[maxn];
vector <pii> ans;
void change(int i, int j) {
    if(i == j) return;
    ans.push_back(make_pair(i, j));
    swap(p[i], p[j]);
    pos[p[i]] = i;
    pos[p[j]] = j;
}
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    for(int i = 2; i <= n-1; i++) {
        if(p[i] == i) continue;
        if(i <= n/2) {
            if (pos[i] > n / 2) {
                change(1, pos[i]);
            }
            change(pos[i], n);
            change(i, n);
        } else {
            change(pos[i], 1);
            change(1, i);
        }
    }
    if(p[1] != 1) change(1, n);
    cout << ans.size() << "\n";
    for(const auto &to: ans) {
        cout << to.first << " " << to.second << "\n";
    }
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