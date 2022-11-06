#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int n, k, i;
string s;

bool ask(int x) {
    printf("1 %d %d\n", x, x + 1);
    fflush(stdout);
    cin >> s;
    if (s == "TAK") return true;
    return false;
}

bool ask2(int x, int y) {
    printf("1 %d %d\n", x, y);
    fflush(stdout);
    cin >> s;
    if (s == "TAK") return true;
    return false;
}

int bs(int l, int r, int bonus) {
    if (l == r) return l;

    int mid = (l + r + bonus) >> 1;
    if (mid == r) mid--;

    if (ask(mid))
        return bs(l, mid, bonus);
    else
        return bs(mid + 1, r, bonus);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k;
    if (k == n) {
        printf("2 1 2");
        return 0;
    }

    int x = bs(1, n, 0);

    if (x == 1) {
        int y = bs(2, n, 1);
        printf("2 %d %d\n", x, y);
        fflush(stdout);
        return 0;
    }

    if (x == n) {
        int y = bs(1, n - 1, 0);
        printf("2 %d %d\n", x, y);
        fflush(stdout);
        return 0;
    }

    int y1 = bs(1, x - 1, 0);
    int y2 = bs(x + 1, n, 1);
    int y;

    if (ask2(y1, y2))
        y = y1;
    else
        y = y2;

    printf("2 %d %d\n", x, y);
    fflush(stdout);

    return 0;
}