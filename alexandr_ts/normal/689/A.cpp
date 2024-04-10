#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 3;
const int INF = 2e9 + 1;

string num = "0123456789";
int dx[] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
int dy[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
            if (!i && !j) continue;
            vector <int> a, b;
            fr(i1, n) {
                a.pb(dx[s[i1] - '0'] + i);
                b.pb(dy[s[i1] - '0'] + j);
            }
            bool ok = true;
            fr(i1, n) {
                bool found = false;
                fr(j1, 10)
                    if (a[i1] == dx[j1] && b[i1] == dy[j1])
                        found = true;
                if (!found) ok = false;
            }
            if (ok) {
                cout << "NO";
                return 0;
            }
        }
    cout << "YES";
}