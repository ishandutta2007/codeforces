#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <int> best;
vector <int> get_best;
vector <vector <int>> a;
int m;

void gen(int cur, int mask = 0, int mn = 1e9 + 5, int iter = 0) {
    if (iter == m) {
        if (mn > best[mask]) {
            best[mask] = mn;
            get_best[mask] = cur;
        }
        return;
    }
    gen(cur, mask, mn, iter + 1);
    gen(cur, mask | (1 << iter), min(mn, a[cur][iter]), iter + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> m;
    best.resize(1 << m, -1);
    get_best.resize(1 << m);
    a.resize(n, vector <int> (m));
    forn (i, 0, n) {
        forn (j, 0, m)
            cin >> a[i][j];
        gen(i);
    }
    /*forn (i, 0, 1 << m) {
        cout << best[i] << " " << get_best[i] << "\n";
    }*/
    int ans = -1;
    int ans_i, ans_j;
    forn (i, 0, n) {
        forn (j, 0, m) {
            int needed = 0;
            forn (k, 0, m)
                if (a[i][k] < a[i][j])
                    needed |= (1 << k);
            if (best[needed] >= a[i][j]) {
                if (a[i][j] > ans) {
                    ans = a[i][j];
                    ans_i = i;
                    ans_j = get_best[needed];
                }
            }
        }
    }
    //cout << ans;
    cout << ans_i + 1 << " " << ans_j + 1;
    return 0;
}