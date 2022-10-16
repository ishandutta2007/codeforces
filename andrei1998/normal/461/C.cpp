#include <iostream>
#include <algorithm>

#define lsb(x) ((x) & (-(x)))
using namespace std;

const int NMAX = 100005;

int n;
int v[NMAX];
int aib[NMAX];

void init() {
    for (int i = 1; i <= n; ++ i)
        v[i] = 1, aib[i] = lsb(i);
}

void update(int pos, int val) {
    v[pos] += val;
    for (; pos <= n; pos += lsb(pos))
        aib[pos] += val;
}

int query(int pos) {
    int ans = 0;
    for (; pos; pos -= lsb(pos))
        ans += aib[pos];
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int q = 0;
    cin >> n >> q;
    init();

    bool reversed = false;
    int st = 1, dr = n;

    int type, l, r, p;
    while (q --) {
        cin >> type;
        if (type == 1) {
            cin >> p;

            if (!reversed)
                p = st + p - 1;
            else
                p = dr - p;

            int p1 = p;
            int p2 = p + 1;
            if (p - st + 1 < dr - p) {
                while (p1 >= st && p2 <= dr) {
                    update(p2, v[p1]);

                    -- p1;
                    ++ p2;
                }

                st = p + 1;

                if (reversed)
                    reversed = false;
            }
            else {
                while (p1 >= st && p2 <= dr) {
                    update(p1, v[p2]);

                    -- p1;
                    ++ p2;
                }

                dr = p;

                if (!reversed)
                    reversed = true;
            }
        }
        else {
            cin >> l >> r;
            ++ l;

            if (!reversed) {
                l = l + st - 1;
                r = r + st - 1;
            }
            else {
                l = dr - l + 1;
                r = dr - r + 1;

                swap(l, r);
            }

            cout << query(r) - query(l - 1) << '\n';
        }
    }

    return 0;
}