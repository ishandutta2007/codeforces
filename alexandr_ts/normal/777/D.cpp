#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 10;
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

string s[N];
int pref[N];
int cmp[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> s[i];
        s[i].erase(0, 1);
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < min(s[i].size(), s[i + 1].size()); j++)
            if (s[i][j] != s[i + 1][j]) {
                if (s[i][j] > s[i + 1][j])
                    s[i] = s[i].substr(0, j);
                break;
            }
        if (s[i] > s[i + 1])
            s[i] = s[i + 1];
    }
    for (int i = 0; i < n; i++)
        cout << "#" + s[i] << endl;
}