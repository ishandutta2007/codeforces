//11:22 (36 - 37) 14:08
#include <iostream>

#define NMAX 200005
using namespace std;

struct domino {
    int st, dr;

    domino (int st = 0, int dr = 0): st(st), dr(dr) {}
} v[NMAX], stiva[NMAX];
int cine[NMAX];

int ext[NMAX]; //Pana unde se extinde in dreapta segmentul i
int dist[NMAX]; //Distanta pana la urmatorul segment
int which[NMAX]; //Care este urmatorul segment

int dp[18][NMAX]; //Coordonata maxima (exprimata ca indice) la care poti ajunge din 2 ^ i salturi (plecand din j)
int cost[18][NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int l;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].st >> l;
        v[i].dr = v[i].st + l;
    }

    int pos = 0, dr;
    for (int i = n; i >= 1; i--) {
        dr = v[i].dr;

        while (pos && v[i].dr >= stiva[pos].st) {
            dr = stiva[pos].dr;
            pos--;
        }

        ext[i] = max(dr, v[i].dr);
        stiva[++ pos] = domino(v[i].st, ext[i]);
        cine[pos] = i;

        if (pos > 1) {
            dist[i] = stiva[pos - 1].st - stiva[pos].dr;
            which[i] = cine[pos - 1];
        }
        else
            which[i] = i;

    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = which[i];
        cost[0][i] = dist[i];
    }

    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            cost[i][j] = cost[i - 1][j] + cost[i - 1][dp[i - 1][j]];
        }

    int q = 0;
    cin >> q;

    int x, y;

    int sum = 0, ans = 0, step, old;
    while (q--) {
        cin >> x >> y;
        old = x;

        ans = 0;
        if (ext[x] >= v[y].st)
            ans = -1;
        else for (step = 17; step + 1; step--)
            if (ext[dp[step][x]] < v[y].st) {
                ans += (1 << step);
                x = dp[step][x];
            }

        ans ++;
        sum = 0;
        x = old;

        for(step = 17; step + 1; step--)
            if ((1 << step) <= ans) {
                ans -= (1 << step);
                sum += cost[step][x];

                x = dp[step][x];
            }

        cout << sum << '\n';
    }

    return 0;
}