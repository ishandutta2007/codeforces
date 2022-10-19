#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const char cc[4] = {'W', 'S', 'A', 'D'};
const int xx[4] = {-1, 1, 0, 0};
const int yy[4] = {0, 0, -1, 1};
 
int n;
char aa[N], a[N];
 
int px[N], py[N];
int minpx[N], maxpx[N], minpy[N], maxpy[N];
int sx[N], sy[N];
int minsx[N], maxsx[N], minsy[N], maxsy[N];
void solv()
{
    cin >> aa;
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1];
    for (int i = 1; i <= n; ++i)
    {
        px[i] = px[i - 1];
        py[i] = py[i - 1];
        for (int j = 0; j < 4; ++j)
        {
            if (a[i] == cc[j])
            {
                px[i] += xx[j];
                py[i] += yy[j];
            }
        }
        maxpx[i] = max(maxpx[i - 1], px[i]);
        minpx[i] = min(minpx[i - 1], px[i]);
        maxpy[i] = max(maxpy[i - 1], py[i]);
        minpy[i] = min(minpy[i - 1], py[i]);
    }
    sx[n + 1] = 0;
    sy[n + 1] = 0;
    maxsx[n + 1] = maxsy[n + 1] = minsx[n + 1] = minsy[n + 1] = 0;
    int maxx = 0, minx = 0, maxy = 0, miny = 0;
    for (int i = n; i >= 1; --i)
    {
        sx[i] = sx[i + 1];
        sy[i] = sy[i + 1];
        for (int j = 0; j < 4; ++j)
        {
            if (a[i] == cc[j])
            {
                sx[i] += xx[j];
                sy[i] += yy[j];
            }
        }
        maxx = max(maxx, sx[i]);
        minx = min(minx, sx[i]);
        maxy = max(maxy, sy[i]);
        miny = min(miny, sy[i]);
        maxsx[i] = sx[i] - minx;
        minsx[i] = sx[i] - maxx;
        maxsy[i] = sy[i] - miny;
        minsy[i] = sy[i] - maxy;
    }
    long long ans = (maxpx[n] - minpx[n] + 1) * 1LL * (maxpy[n] - minpy[n] + 1);
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int maxx = maxpx[i];
            int minx = minpx[i];
            int maxy = maxpy[i];
            int miny = minpy[i];
            maxx = max(maxx, px[i] + xx[j]);
            minx = min(minx, px[i] + xx[j]);
            maxy = max(maxy, py[i] + yy[j]);
            miny = min(miny, py[i] + yy[j]);
            maxx = max(maxx, px[i] + xx[j] + maxsx[i + 1]);
            minx = min(minx, px[i] + xx[j] + minsx[i + 1]);
            maxy = max(maxy, py[i] + yy[j] + maxsy[i + 1]);
            miny = min(miny, py[i] + yy[j] + minsy[i + 1]);
            ans = min(ans, (maxx - minx + 1) * 1LL * (maxy - miny + 1));
        }
    }
    cout << ans << endl;
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}