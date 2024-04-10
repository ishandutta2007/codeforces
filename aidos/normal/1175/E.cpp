#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
vector<int> L[maxn];
vector<int> R[maxn];
int p[21][maxn];
int n, m;
int ans[maxn];
vector<pair<int, int> > qu[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l++;
        r++;
        l *= 2;
        r *= 2;
        L[r].emplace_back(l);
        R[l].emplace_back(l);
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x++;
        y++;
        x *= 2;
        y *= 2;
        qu[y].emplace_back(make_pair(x, i));
    }
    multiset<int> S;
    for(int i = 1; i < maxn; i++) {
        for(int pos: R[i]) S.insert(i);
        if(S.size() > 0) p[0][i] = *S.begin();
        for(int j = 1; j < 21; j++) {
            p[j][i] = p[j-1][p[j-1][i]];
        }
        for(int pos: L[i]) {
            S.erase(S.find(pos));
        }
        for(pair<int, int> x: qu[i]) {
            int z = i;
            int cur = 0;
            for(int j = 20; j >= 0; j--) {
                if(p[j][z] > x.first) {
                    cur += (1<<j);
                    z = p[j][z];
                }
            }
            if(p[0][z] != 0 && p[0][z] <= x.first) {
                ans[x.second] = cur + 1;
            }else {
                ans[x.second] = -1;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}