#include <bits/stdc++.h>

using namespace std;

int n;

int query(int x1, int y1, int x2, int y2)
{
    assert(x1 <= x2 && y1 <= y2);
    cout << "?" << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int get(int y, int ge, int cmp = 2, int a = 1, int b = 1, int c = n, int d = n)
{
    int les = !ge;
    vector<int> base = {a, b, c, d};
    int l = (y ? base[1] : base[0]) - !les, r = (y ? base[3] : base[2]) + les;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        base[2 * (!les) + y] = m;
        int ans = query(base[0], base[1], base[2], base[3]);
        if((ans >= cmp) == (les == 1))
            l = m;
        else
            r = m;
    }
    return les ? l : r;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int xm = get(0, 1, 1);
    int ym = get(1, 1, 1);
    if(xm != n && query(xm + 1, 1, n, n) == 1)
    {
        assert(query(1, 1, xm, n) == 1);
        int x1 = get(0, 0, 1, 1, 1, xm, n);
        int y1 = get(1, 0, 1, 1, 1, xm, n);
        int x2 = get(0, 1, 1, 1, 1, xm, n);
        int y2 = get(1, 1, 1, 1, 1, xm, n);
        int x3 = get(0, 0, 1, xm + 1, 1, n, n);
        int y3 = get(1, 0, 1, xm + 1, 1, n, n);
        int x4 = get(0, 1, 1, xm + 1, 1, n, n);
        int y4 = get(1, 1, 1, xm + 1, 1, n, n);
        cout << "!" << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' '
                           << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
    }
    else
    {
        assert(query(1, 1, n, ym) == 1);
        assert(query(1, ym + 1, n, n) == 1);
        int x1 = get(0, 0, 1, 1, 1, n, ym);
        int y1 = get(1, 0, 1, 1, 1, n, ym);
        int x2 = get(0, 1, 1, 1, 1, n, ym);
        int y2 = get(1, 1, 1, 1, 1, n, ym);
        int x3 = get(0, 0, 1, 1, ym + 1, n, n);
        int y3 = get(1, 0, 1, 1, ym + 1, n, n);
        int x4 = get(0, 1, 1, 1, ym + 1, n, n);
        int y4 = get(1, 1, 1, 1, ym + 1, n, n);
        cout << "!" << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' '
                           << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
    }
	return 0;
}