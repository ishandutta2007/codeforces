#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e2 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

char a[N][N];
int h[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        fr(j, m) {
            cin >> a[i][j];
            if (a[i][j] == '*')
                h[j] = max(h[j], n - i);
        }
    int up = 0, down = 0;
    fr(i, m - 1) {
        up = max(up, h[i + 1] - h[i]);
        down = max(down, h[i] - h[i + 1]);
    }
    cout << up << " " << down;


}