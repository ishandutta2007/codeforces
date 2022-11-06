#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


const int MxN = (int)5e5 + 9;
int a[MxN + 9];
int b[MxN + 9];

vector<int> adj[MxN + 9];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i)
        cin >> a[i];


    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    assert(v[0] == 1 && v[n-1] == n);

    sort(v.begin(), v.end(), [](const int x, const int y) {
        return a[x] < a[y];
    });

    for(int x : v) {
        set<int> s;
        for(int y:  adj[x])
            if(b[y])
                s.insert(a[y]);
            for(int i = 1;; ++i)
                if(!s.count(i)) {
                    b[x] = i;
                    break;
                }
            if(b[x] != a[x]) {
                cout << -1;
                return 0;
            }
    }
    for(int x : v)
        cout << x << ' ';

    return 0;
}