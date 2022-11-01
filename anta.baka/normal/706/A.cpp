#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double a, b;
    cin >> a >> b >> n;
    double ans = 1e11;
    for(int i = 0; i < n; i++) {
        double x, y, v;
        cin >> x >> y >> v;
        double t = sqrt((a-x)*(a-x) + (b-y)*(b-y)) / v;
        if(t < ans)
            ans = t;
    }
    cout.precision(7);
    cout << fixed << ans;
    return 0;
}