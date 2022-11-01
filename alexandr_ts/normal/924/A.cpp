#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>


using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

string s[N];

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    bool ok = true;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            bool eq = false;
            for (int k = 0; k < m; k++)
                if (s[i][k] == '#' && s[j][k] == '#')
                    eq = true;
            if (eq)
                for (int k = 0; k < m; k++)
                    if (s[i][k] != s[j][k])
                        ok = false;
        }
    if (ok)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();

}