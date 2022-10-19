#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <int> kol_inv_nul, kol_inv_one;

void gen(vector <int>& a, int lvl) {
    if (a.empty() || lvl < 0) return;
    if (lvl == 3) {
        int oru = 0;
    }
    int kol = 0, nul = 0, one = 0, kol1 = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if ((a[i] >> lvl) & 1) kol += nul;
        else ++nul;
        if ((a[i] >> lvl) & 1) ++one;
        else kol1 += one;
    }
    kol_inv_nul[lvl] += kol;
    kol_inv_one[lvl] += kol1;
    vector <int> oneee, nulll;
    for (int i : a) {
        if ((i >> lvl) & 1) oneee.push_back(i);
        else nulll.push_back(i);
    }
    gen(oneee, lvl - 1);
    gen(nulll, lvl - 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    kol_inv_nul.resize(32);
    kol_inv_one.resize(32);
    gen(a, 31);
    int ans = 0, kolinv = 0;
    for (int i = 0; i < 32; ++i) {
        if (kol_inv_one[i] < kol_inv_nul[i]) ans += (1 << i);
        kolinv += min(kol_inv_nul[i], kol_inv_one[i]);
    }
    cout << kolinv << " " << ans;
}