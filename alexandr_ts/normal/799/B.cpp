#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2e5 + 10;
const int M = 1e3 + 10;

pair <int, pair <int, int> > a[N];

vector <int> b[3][3];

int cur[3][3];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].f;
    }
    fr(i, n) {
        cin >> a[i].s.f;
        a[i].s.f--;
    }
    fr(i, n) {
        cin >> a[i].s.s;
        a[i].s.s--;
    }

    sort(a, a + n);
    fr(i, n) {
        b[a[i].s.f][a[i].s.s].pb(i);
    }

    int m;
    cin >> m;
    fr(i, m) {
        int col;
        cin >> col;
        col--;
        int ansi = -1, ansj = -1, ansc = INF;
        fr(i1, 3)
            fr(j1, 3) {
                if (i1 == col || j1 == col)
                    if (cur[i1][j1] < b[i1][j1].size())
                        if (a[b[i1][j1][cur[i1][j1]]].f < ansc)
                            ansc = a[b[i1][j1][cur[i1][j1]]].f, ansi = i1, ansj = j1;
            }
        if (ansi == -1)
            cout << -1 << " ";
        else {
            cur[ansi][ansj]++;
            cout << ansc << " ";
        }
    }

}