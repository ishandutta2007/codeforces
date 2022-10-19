#include <bits/stdc++.h>

using namespace std;

const int M = 100100;
const int INF = 100001000;

int m, k, a[M], fr;
bool fin[M];

void read() {
    cin >> m >> k;
    for (int i = 1; i <= k; ++i)
        cin >> a[i];
}

void kill() {

    fr = 0;
    bool firstNo = false;

    for (int i = 1; i <= k; ++i)
        fin[i] = false;

    for (int i = 1; i <= m - 1; ++i) {
        int t, r;
        cin >> t >> r;

        if (r == 1 && !firstNo) {
            firstNo = true;
            for (int i = 1; i <= k; ++i)
                if (a[i] <= fr)
                    fin[i] = true;
        }

        if (t > 0) {
            a[t]--;
            if (firstNo)
                fin[t] = false;
        } else {
            ++fr;
        }
    }

    int cnt = INF;
    for (int i = 1; i <= k; ++i)
        if (fin[i])
            cnt = min(cnt, a[i]);

    if (!firstNo)
        cnt = 0;

    for (int i = 1; i <= k; ++i) {
        bool ans;
        if (fin[i])
            ans = true;
        else if (a[i] <= fr - cnt)
            ans = true;
        else
            ans = false;
        cout << (ans ? "Y":"N");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        read();
        kill();
    }
    return 0;
}