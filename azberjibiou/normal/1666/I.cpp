#include <iostream>
#include <algorithm>
using namespace std;

int qry(int x, int y, bool f = false)
{
    if (!f) 
        cout << "SCAN " << x << " " << y << endl;
    else
        cout << "DIG " << x << " " << y << endl;
    int t; cin >> t;
    return t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    for (int ti = 0; ti < tc; ti++) {
        int n, m; cin >> m >> n;
        int p0 = qry(1, 1) + 4, p1 = qry(m, 1) + 2;
        int ys = (p0 + p1 - 2 * m) / 2, xs = p0 - ys;
        int px = xs / 2, py = ys / 2;
        int rs = qry(px, py);
        int cs = (p0 - rs) / 2;
        int xd0 = (qry(1, py) + 2 - rs) / 2, yd0 = cs - xd0;
        int xd1 = xs - xd0, yd1 = ys - yd0;
        int t = qry(xd0, yd0, true);
        if (t) 
            qry(xd1, yd1, true);
        else {
            qry(xd0, yd1, true);
            qry(xd1, yd0, true);
        }
    }
    return 0;
}