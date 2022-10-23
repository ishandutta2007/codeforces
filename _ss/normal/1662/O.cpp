#include <bits/stdc++.h>
using namespace std;

bool blockIn[30][360], blockOut[30][360], blockCW[30][360], blockCCW[30][360], vst[30][360];

void solve() {
    memset(blockIn, 0, sizeof(blockIn));
    memset(blockOut, 0, sizeof(blockOut));
    memset(blockCCW, 0, sizeof(blockCCW));
    memset(blockCW, 0, sizeof(blockCW));
    memset(vst, 0, sizeof(vst));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'C') {
            int r, t1, t2;
            cin >> r >> t1 >> t2;
            while (t1 != t2) {
                blockOut[r][t1] = true;
                blockIn[r + 1][t1] = true;
                t1 = (t1 + 1) % 360;
            }
        } else {
            int r1, r2, t;
            cin >> r1 >> r2 >> t;
            ++r1;
            while (r1 <= r2) {
                blockCW[r1][(t - 1 + 360) % 360] = true;
                blockCCW[r1][t] = true;
                ++r1;
            }
        }
    }

    queue<array<int, 2>> qu;
    for (int i = 0; i < 360; ++i) {
        vst[1][i] = true;
        qu.push({1, i});
    }
    while (!qu.empty()) {
        int d = qu.front()[0];
        int ang = qu.front()[1];
        qu.pop();
        if (d > 20) {
            cout << "YES\n";
            return;
        }
        if (!blockCCW[d][ang] && !vst[d][(ang - 1 + 360) % 360]) {
            vst[d][(ang - 1 + 360) % 360] = true;
            qu.push({d, (ang - 1 + 360) % 360});
        }
        if (!blockCW[d][ang] && !vst[d][(ang + 1) % 360]) {
            vst[d][(ang + 1) % 360] = true;
            qu.push({d, (ang + 1) % 360});
        }
        if (d > 1 && !blockIn[d][ang] && !vst[d - 1][ang]) {
            vst[d - 1][ang] = true;
            qu.push({d - 1, ang});
        }
        if (!blockOut[d][ang] && !vst[d + 1][ang]) {
            vst[d + 1][ang] = true;
            qu.push({d + 1, ang});
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}

/*
1
2
C 20 90 180
C 20 181 90
*/