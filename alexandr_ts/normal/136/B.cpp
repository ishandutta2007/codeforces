#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 2e5;
const int INF = 2e9;

int pows[N], pa[N], pc[N], pb[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int a, c;
    cin >> a >> c;
    int a1 = a, c1 = c;
    pows[0] = 1;
    frab(i, 1, 20)
        pows[i] = pows[i - 1] * 3;
    for (int j = 19; j >= 0; j--) {
        pa[j] = a1 / pows[j];
        if (pa[j])
            a1 %= (pa[j] * pows[j]);
        pc[j] = c1 / pows[j];
        if (pc[j])
            c1 %= (pc[j] * pows[j]);
    }
    fr(i, 20)
        fr(j, 3)
            if ((pa[i] + j) % 3 == pc[i]) {
                pb[i] = j;
                break;
            }
    int ans = 0;
    fr(i, 20)
        ans += pb[i] * pows[i];
    cout << ans;

}