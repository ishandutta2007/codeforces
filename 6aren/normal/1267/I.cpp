#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 205;

bool check[N][N];
int w[N];

bool cmp(int x, int y) {
    return !check[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> win;
        vector<int> lose;
        for (int i = 1; i <= n; i++) {
            cout << "? " << i << ' ' << i + n << endl;
            char foo;
            cin >> foo;
            if (foo == '<') {
                win.pb(i + n);
                lose.pb(i);
                w[i] = i + n;
            } else {
                win.pb(i);
                lose.pb(i + n);
                w[i + n] = i;
            }
        }
        for (int i = 0; i < lose.size(); i++) {
            for (int j = i + 1; j < lose.size(); j++) {
                int u = lose[i];
                int v = lose[j];
                cout << "? " << lose[i] << ' ' << lose[j] << endl;
                char foo;
                cin >> foo;
                if (foo == '<') check[u][v] = 1;
                else check[u][v] = 0;
                check[v][u] = (check[u][v] ^ 1);
            }
        }
        sort(all(lose), cmp);
        int pivot = w[lose[1]];
        for (int e : win) {
            if (e != w[lose[0]] && e != w[lose[1]]) {
                cout << "? " << w[lose[1]] << " " << e << endl;
                char foo;
                cin >> foo;
                if (foo == '<') {
                    pivot = e;
                }
            }
        }
        vector<int> v;
        for (int i = 1; i <= 2 * n; i++) {
            if (i == w[lose[0]] || i == pivot) continue;
            v.pb(i);
            for (int j = i + 1; j <= 2 * n; j++) {
                if (j == w[lose[0]] || j == pivot) continue;
                cout << "? " << i << ' ' << j << endl;
                char foo;
                cin >> foo;
            }
        }
        cout << "!" << endl;
    }
    return 0;
}