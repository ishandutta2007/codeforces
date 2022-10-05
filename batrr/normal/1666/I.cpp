#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
int n, m;
int R1 = 5;
int R2 = 8;
int C1 = 14;
int C2 = 12;
int DIG(int r, int c) {
    cout << "DIG " << r << " " << c << endl;
#ifdef DEBUG
        return ((R1 == r  && C1 == c) || (R2 == r && C2 == c));
#endif
    int resp;
    cin >> resp;
    return resp;
}
int SCAN(int r, int c) {
    cout << "SCAN " << r << " " << c << endl;
#ifdef DEBUG
    return abs(R1 - r) + abs(R2 - r) + abs(C1 - c) + abs(C2 - c);
#endif
    int resp;
    cin >> resp;
    return resp;
}
void solve()
{
#ifdef DEBUG
    n = 16;
    m = 16;
#else
    cin >> n >> m;
#endif
    int f11 = SCAN(1, 1);
    int fn1 = SCAN(n, 1);
    int sum_c = (f11 + fn1 - 2 * n + 2 + 4);
    assert(sum_c % 2 == 0 && sum_c >= 0);
    sum_c /= 2;
    int sum_r = f11 + 4 - sum_c;
    int delta_r = SCAN(sum_r / 2, 1);
    delta_r -= (sum_c - 2);
    int r1 = (delta_r + sum_r) / 2;
    int r2 = (sum_r - delta_r) / 2;
    int delta_c = SCAN(1, sum_c / 2);
    delta_c -= (sum_r - 2);
    int c1 = (delta_c + sum_c) / 2;
    int c2 = (sum_c - delta_c) / 2;
    if (DIG(r1, c1)) {
        assert(DIG(r2, c2));
    }
    else {
        assert(DIG(r1, c2));
        assert(DIG(r2, c1));
    }


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int t = 1;
    // scanf ("%d", &t);
    cin >> t;
    while (t--)
        solve();
}