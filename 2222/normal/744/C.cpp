#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)      for(int i(a),b_(b);i<b_;++i)
#define REP(i,n)        for(int i=0;i<n;++i)
#define CL(a,x)         memset(a,x,sizeof(a))
#define all(a)          (a).begin(),(a).end()
#define sz(a)           int((a).size())
#define pb              push_back
#define X               first
#define Y               second
using ll =              long long;
using vi =              vector<int>;
using pii =             pair<int, int>;

char c[20];
int r[20], b[20], n;
int F[256][1 << 16];

int f(int mask, int haveR, int haveB, int cardsR, int cardsB) {
    if (mask == 0) return 0;
    int &res = F[(haveR - haveB) & 255][mask];
    if (res < 0) {
        res = -1u/4;
        REP (i, n) {
            if (~mask & 1 << i) continue;
            int needR = max(r[i] - cardsR, 0);
            int needB = max(b[i] - cardsB, 0);
            int take = max(max(needR - haveR, needB - haveB), 0);
            res = min(res, take + f(mask ^ (1 << i),
                                    haveR + take - needR,
                                    haveB + take - needB,
                                    cardsR + (c[i] == 'R'),
                                    cardsB + (c[i] == 'B')));
        }
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    int greedyR = 0, greedyB = 0;
    REP (i, n) {
        cin >> (c + i) >> r[i] >> b[i];
        greedyR += max(r[i] - n, 0);
        greedyB += max(b[i] - n, 0);
        r[i] = min(r[i], n);
        b[i] = min(b[i], n);
    }
    CL(F, -1);
    int greedy = max(greedyR, greedyB);
    cout << greedy + n + f((1 << n) - 1, greedy - greedyR, greedy - greedyB, 0, 0) << endl;
    return 0;
}