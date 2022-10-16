#include <iostream>
#include <iomanip>

using namespace std;

double rock[105][105][105];
bool done_rock[105][105][105];

double win_rock (int r, int s, int p) {
    if (r < 0 || s < 0 || p < 0)
        return 0;

    if (done_rock[r][s][p])
        return rock[r][s][p];
    done_rock[r][s][p] = true;

    if (r > 0 && s == 0 && p == 0) {
        rock[r][s][p] = 1;
        return 1;
    }
    if (r == 0 && s > 0 && p == 0)
        return 0;
    if (r == 0 && s == 0 && p > 0)
        return 0;

    int pairs = (r + s + p) * (r + s + p - 1) / 2;

    int rs = r * s;
    int rp = r * p;
    int sp = s * p;

    int rr = r * (r - 1) / 2;
    int ss = s * (s - 1) / 2;
    int pp = p * (p - 1) / 2;

    rock[r][s][p] = ((double)(rp * win_rock(r - 1, s, p) + rs * win_rock(r, s - 1, p) + sp * win_rock(r, s, p - 1))) / (pairs - rr - ss - pp);

    return rock[r][s][p];
}

int main()
{
    int r, s, p;
    cin >> r >> s >> p;

    cout << fixed << setprecision(10) << win_rock(r, s, p) << ' ' << win_rock(s, p, r) << ' ' << win_rock(p, r, s) << '\n';
    return 0;
}