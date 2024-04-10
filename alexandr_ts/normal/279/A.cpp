#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 2e3;
const int INF = 2e9;

int a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int x, y;
    cin >> x >> y;
    x += 1000, y += 1000;
    int x1 = 1000, y1 = 1000, cur = 0;
    frab(i, 1, 250) {
        fr(j, 2 * (i - 1) + 1)
            a[x1++][y1] = cur;
        cur++;
        fr(j, 2 * (i - 1) + 1)
            a[x1][y1++] = cur;
        cur++;
        fr(j, 2 * i)
            a[x1--][y1] = cur;
        cur++;
        fr(j, 2 * i)
            a[x1][y1--] = cur;
        cur++;
    }
    int add = 0;
    if (x - 1001 == -y + 1000 && x - 1000 >= 1) add++;
    if (x - 1000 < 0 || y - 1000 > 0)
        if (abs(x - 1000) == abs(y - 1000))
            add++;
    cout << a[x][y] - add;// << " " << add;
}