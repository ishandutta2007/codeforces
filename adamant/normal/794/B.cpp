#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    double cur = 0;
    for(int i = 0; i < n - 1; i++)
    {
        //h / (n) = (cur + (cur + t)) / (h)

        double t = -cur + sqrt(cur * cur + 1. * h * h / n);
        cur += t;
        cout << fixed << setprecision(9) << cur << endl;
    }
}