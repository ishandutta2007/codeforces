#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6, INF = 1e9;
using ld = double;

int n, m, a[100], b[100], c[100][100];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int bit = 0; bit < 30; bit++) {
        vector<int> aa, bb;
        for(int i = 0; i < n; i++) if(a[i] & (1 << bit)) aa.push_back(i);
        for(int i = 0; i < m; i++) if(b[i] & (1 << bit)) bb.push_back(i);
        if(sz(aa) % 2 != sz(bb) % 2) return cout << "NO", 0;
        int sa = sz(aa) - sz(aa) % 2;
        for(int i = 0; i < sa; i++) c[aa[i]][0] ^= (1 << bit);
        int sb = sz(bb) - sz(bb) % 2;
        for(int i = 0; i < sb; i++) c[0][bb[i]] ^= (1 << bit);
        if(sz(aa) % 2) c[aa.back()][bb.back()] ^= (1 << bit);
    }
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < m; j++) {
//            a[i] ^= c[i][j];
//            b[j] ^= c[i][j];
//        }
//    for(int i = 0; i < n; i++) assert(a[i] == 0);
//    for(int i = 0; i < m; i++) assert(b[i] == 0);
    cout << "YES\n";
    for(int i = 0; i < n; i++, cout << '\n')
        for(int j = 0; j < m; j++)
            cout << c[i][j] << ' ';
}