#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = (int) 1e9 + 7;
const int MxN = (int) 2e5 + 9;

int n;
ll g = 1;
unordered_map<int, int> a[MxN + 9];
unordered_map<int, int> cnts;

unordered_map<int, int> getFact(int x) {
    unordered_map<int, int> res;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i) continue;
        int cnt = 0;
        do {
            cnt++;
            x /= i;
        } while (x % i == 0);
        res[i] = cnt;
    }
    if (x > 1)
        res[x]++;
    return move(res);
}

void update(const int i, const int x) {

    auto fact = getFact(x);
    for (auto e : fact) {
        if(!a[i].count(e.first))
            ++cnts[e.first];
        else
            assert(a[i].at(e.first) > 0);
        a[i][e.first] += e.second;
        if(cnts[e.first] < n)
            continue;
        {
            int mn = (int)1e9;
            for(int i = 1; i <= n; ++i)
                mn = min(mn, a[i].at(e.first));
            assert(mn > 0);
            for(int i = 1; i <= n; ++i) {
                a[i][e.first] -= mn;
                if(a[i][e.first] == 0) {
                    a[i].erase(e.first);
                    --cnts[e.first];
                }
            }
            for(int rep = 0; rep < mn; ++rep)
                (g *= e.first) %= mod;
        }
    }

}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        update(i, x);
    }
    while (q--) {
        int i, x;
        cin >> i >> x;
        update(i, x);
        cout << g << '\n';
    }
    return 0;
}