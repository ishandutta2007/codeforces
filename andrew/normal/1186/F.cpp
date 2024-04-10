#include <bits/stdc++.h>
using namespace std;
#define M make_pair
#define F first
#define S second
#define pb push_back

typedef pair <int, int> pii;

int n, m;
set <int> nx[1000100];
vector <pii> nw;
int a[1000100];
vector <pii> ans;
set <pii> order;
set <pii> lst;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie();
    cout.tie();

    srand(23095);

    cin >> n >> m;
//    n = 1000000;
//    m = 1000000;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
//        x = (rand() * rand()) % n;
//        y = (rand() * rand()) % n;
        nx[x].insert(y);
        nx[y].insert(x);
        a[x]++;
        a[y]++;
    }
    for (int i = 0; i < n; i++) {
        a[i] = (a[i] / 2) + (a[i] % 2);
        order.insert(M(a[i], i));
    }
    while (!order.empty()) {
        int v = order.begin() -> S;
        order.erase(order.begin());
        nw.clear();
        for (auto u : nx[v]) {
            nw.pb(M(a[u], u));
        }
        sort(nw.rbegin(), nw.rend());
        for (int j = 0; a[v] > 0; j++) {
            a[v]--;

            if (a[nw[j].S] > 0) {
                order.erase(M(a[nw[j].S], nw[j].S));
            }
            a[nw[j].S]--;
            if (a[nw[j].S] > 0) {
                order.insert(M(a[nw[j].S], nw[j].S));
            }

            ans.pb(M(v, nw[j].S));
            nx[v].erase(nw[j].S);
            nx[nw[j].S].erase(v);
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.F+1 << " " << i.S+1 << '\n';
    }


    return 0;
}