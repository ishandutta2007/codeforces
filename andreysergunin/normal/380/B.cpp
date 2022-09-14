#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

const int MAXC = 1e6 + 100;

struct node{
    node() : left(0), right(0) {};
    int left;
    int right;
};

bool intersect (int l1, int r1, int l2, int r2) {
    return !(r2 < l1 || r1 < l2);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > segl(n), segr(n), val(n);
    vector<bool> b(MAXC);
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int t, l, r, x;
            cin >> t >> l >> r >> x;
            t--; l--; r--;
            segl[t].push_back(l);
            segr[t].push_back(r);
            val[t].push_back(x);
        }
        else {
            int t, v;
            cin >> t >> v;
            t--; v--;
            int l = v, r = v;
            int ans = 0;
            for (int j = t; j < n; j++) {
                for (int k = 0; k < val[j].size(); k++)
                    if (intersect(l, r, segl[j][k], segr[j][k])) {
                        if (b[val[j][k]] == 0)
                            ans++;
                        b[val[j][k]] = 1;
                    }
                if (j < n - 1) {
                    int s = 1;
                    int t = l;
                    while (s < l + 1) {
                        t++;
                        s *= 2;
                    }
                    l = t;
                    
                    t = r;
                    s = 1;
                    while (s <= r + 1) {
                        t++;
                        s *= 2;
                    }
                    r = t;
                }
            }
            for (int j = t; j < n; j++)
                for (int k = 0; k < val[j].size(); k++)
                    b[val[j][k]] = 0;
            cout << ans << endl;
        }
    }
    return 0;
}