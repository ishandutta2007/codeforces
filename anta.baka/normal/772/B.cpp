#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int N = 1010;

int n;
ld x[N], y[N], ans = numeric_limits<ld>::max();

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0]; y[n] = y[0];
    x[n+1] = x[1]; y[n+1] = y[1];
    for(int i = 0; i < n; ++i)
    {
        ld A = y[i]-y[i+2], B = x[i+2]-x[i], C = x[i]*y[i+2]-x[i+2]*y[i];
        ld dist = (A*x[i+1] + B*y[i+1] + C)/sqrt(A*A+B*B);
        ans = min(ans, dist/2.0);
    }
    cout << fixed << setprecision(10) << ans;
}