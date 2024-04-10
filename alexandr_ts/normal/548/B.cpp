#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 1e3;
const ll INF = 2e9 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

int ans[N];
int a[N][N];
int n, m, q;

void recalc(int i) {
    int curans = 0;
    int cnt = 0;
    fr(j, m)
        if (a[i][j])
            cnt++;
        else {
            curans = max(curans, cnt);
            cnt = 0;
        }
    curans = max(curans, cnt);
    ans[i] = curans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    fr(i, n)
        fr(j, m)
            cin >> a[i][j];
    fr(i, n)
        recalc(i);

    int i1, j1;
    fr(i, q) {
        cin >> i1 >> j1;
        i1--, j1--;
        a[i1][j1] = !a[i1][j1];
        recalc(i1);
        cout << *max_element(ans, ans + n) << endl;
    }



}