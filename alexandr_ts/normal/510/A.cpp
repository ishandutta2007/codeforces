#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;

int a[N];
vector <int> g[N];
bool used[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        if (!(i % 2))
            for (int j = 0; j < m; j++)
                cout << '#';
        else if (i % 4 == 1) {
            for (int j = 0; j < m - 1; j++)
                cout << ".";
            cout << "#";
        }
        else if (i % 4 == 3) {
            cout << "#";
            for (int j = 0; j < m - 1; j++)
                cout << ".";
        }
        cout << endl;
    }
}