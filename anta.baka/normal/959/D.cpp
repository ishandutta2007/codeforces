#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 2e6 + 1;

vector<int> d;

inline void fac(int x) {
    d.clear();
    for(int j = 2; j * j <= x; j++)
        if(x % j == 0) {
            if(d.empty() || d.back() != j) d.push_back(j);
            x /= j;
            j--;
        }
    if(x != 1) if(d.empty() || d.back() != x) d.push_back(x);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> b(maxn, 0), a(n);
    int pos = -1;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(pos != -1) continue;
        fac(a[i]);
        for(int y : d) if(b[y]++ == 1 && pos == -1) pos = i;
    }

    if(pos != -1) {
        fac(a[pos]);
        for(int y : d) b[y]--;

        for(a[pos]++; ; a[pos]++) {
            fac(a[pos]);
            bool ok = true;
            for(int y : d) ok &= !b[y];
            if(ok) break;
        }

        fac(a[pos]);
        for(int y : d) b[y]++;

        vector<int> p(maxn, 1);
        for(int i = 2; i < maxn; i++)
            if(p[i])
                for(ll j = ll(i) * i; j < maxn; j += i)
                    p[j] = 0;
        for(int t = 2; t < maxn; t++) if(b[t]) p[t] = 0;

        int uk = 2;
        for(int i = pos + 1; i < n; i++) {
            while(!p[uk]) uk++;
            a[i] = uk;
            p[uk] = 0;
        }
    }

    for(int x : a) cout << x << ' ';
}