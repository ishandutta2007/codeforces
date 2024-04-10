#include <iostream>
#include <map>

#define int long long int
using namespace std;

map <long long, long long> h;

int getL(int nr) {
    int ans;
    if (nr < 2)
        ans = 1;
    else
        ans = 2LL * getL(nr / 2) + 1;

    h[nr] = ans;
    return ans;
}

int solve(int nr, int l, int r) {
    if (r < l)
        return 0;
    if (nr <= 1)
        return nr;
    if (l == 1 && r == h[nr])
        return nr;

    int mid = 1 + h[nr / 2];

    int val = nr % 2;

    int ans = 0;
    if (r <= mid) {
        if (r == mid) {
            ans += val;
            -- r;
        }
        ans += solve(nr / 2, l, r);
    }
    else if (l >= mid) {
        if (l == mid) {
            ans += val;
            ++ l;
        }
        ans += solve(nr / 2, l - mid, r - mid);
    }
    else {
        ans += val;
        ans += solve(nr / 2, l, mid - 1);
        ans += solve(nr / 2, 1, r - mid);
    }

    return ans;
}

signed main()
{
    int N;
    cin >> N;

    getL(N);

    int l, r;
    cin >> l >> r;

    cout << solve(N, l, r) << '\n';
    return 0;
}