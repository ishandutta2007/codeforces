#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    int ma = -1;
    for (auto &c : a) {
        cin >> c;
        ma = max(ma, c);
    }
    vector <pair<long long, int>> b(q);
    for (int i = 0; i < q; i++) {
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(b.begin(), b.end());
    vector <pair<int, int>> ans(q);
    deque <int> d;
    for (auto &c : a) {
        d.push_back(c);
    }
    int cnt = 0;
    int j = 0;
    while (d.front() != ma) {
        int fr = d[0];
        int ba = d[1];
        while (j < q && b[j].fi == cnt + 1) {
            ans[b[j].se] = {fr, ba};
            j++;
        }
        cnt++;
        if (fr < ba) {
            swap(fr, ba);
        }
        d.pop_front();
        d.pop_front();
        d.push_front(fr);
        d.push_back(ba);
    }
    vector <int> p;
    for (int i = 1; i < n; i++) {
        p.pb(d[i]);
    }
    while (j < q) {
        ans[b[j].se] = {d.front(), p[(b[j].fi - cnt - 1) % p.size()]};
        j++;
    }
    for (auto &c : ans) {
        cout << c.fi << " " << c.se << "\n";
    }
    return 0;
}