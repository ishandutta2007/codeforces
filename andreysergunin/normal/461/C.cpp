#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

vector<int> f;

void update(int pos, int val) {
    if (pos < 0)
        return;
    for (int i = pos; i < sz(f); i = (i | (i + 1)))
        f[i] += val;
}

int sum(int pos) {
    if (pos < 0)
        return 0;
    int ans = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
        ans += f[i];
    return ans;
}

int get(int pos) {
    return sum(pos) - sum(pos - 1);
}

int main() {
    int n, q;
    cin >> n >> q;
    int l = 0, r = n;
    map<int, int> m;
    f.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        update(i, 1);
    bool rev = false;
    for (int i = 0; i < q; ++i) {
//        cout << l << " " << r << endl;
//        cout << rev << endl;
//        for (int i = 1; i <= n; ++i)
//            cout << get(i) << " ";
//        cout << endl;
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            cin >> pos;
            if (rev)
                pos = (r - l - pos);
            pos += l;
            if (pos <= (r + l) / 2) {
                for (int j = l + 1; j <= pos; ++j) {
                    update(pos + (pos - j) + 1, get(j));
                    update(j, -get(j));
                }
                l = pos;
                if (rev)
                    rev = !rev;
            }
            else {
                for (int j = pos + 1; j <= r; ++j) {
                    update(pos + (pos - j) + 1, get(j));
                    update(j, -get(j));
                }
                r = pos;
                if (!rev)
                    rev = !rev;
            }
        }
        else {
            int a, b;
            cin >> a >> b;
            if (rev) {
                a = (r - l - a);
                b = (r - l - b);
                swap(a, b);
            }
            a += l;
            b += l;
            int ans = sum(b) - sum(a);
            cout << ans << endl;

        }
    }
    return 0;
}