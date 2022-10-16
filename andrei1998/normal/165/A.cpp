#include <bits/stdc++.h>

#define mod 1000000007
#define lint long long int
#define mp make_pair
#define pb push_back
#define lsb(x) ((x) & (-(x)))
using namespace std;

int n;
struct point {
    int x, y;
} v[205];

bool up (const point &c, const point &x) {
    return c.x == x.x && c.y < x.y;
}

bool down (const point &c, const point &x) {
    return c.x == x.x && c.y > x.y;
}

bool left (const point &c, const point &x) {
    return c.y == x.y && c.x > x.x;
}

bool right (const point &c, const point &x) {
    return c.y == x.y && c.x < x.x;
}

bool exists_up (const point &c) {
    for (int i = 1; i <= n; i++)
        if (up(c, v[i]))
            return true;

    return false;
}

bool exists_down (const point &c) {
    for (int i = 1; i <= n; i++)
        if (down(c, v[i]))
            return true;

    return false;
}

bool exists_left (const point &c) {
    for (int i = 1; i <= n; i++)
        if (left(c, v[i]))
            return true;

    return false;
}

bool exists_right (const point &c) {
    for (int i = 1; i <= n; i++)
        if (right(c, v[i]))
            return true;

    return false;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i].x >> v[i].y;

    int nr = 0;
    for (int i = 1; i <= n; i++)
        if (exists_down(v[i]) && exists_left(v[i]) && exists_right(v[i]) && exists_up(v[i]))
            nr ++;

    cout << nr << endl;
    return 0;
}