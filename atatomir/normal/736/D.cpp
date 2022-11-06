#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 2016

int n, m, i, j, x, y;
bitset<maxN> data[maxN], inv[maxN];
vector< pair<int, int> > v;

void inverse() {
    int i, j, k;

    for (i = 0; i < n; i++) inv[i][i] = 1;

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (data[j][i] == 1) {
                swap(data[i], data[j]);
                swap(inv[i], inv[j]);
                break;
            }
        }

        if (j == n) cerr << "error";

        for (j = i + 1; j < n; j++) {
            if (data[j][i] == 0) continue;
            data[j] = data[j] ^ data[i];
            inv[j] ^= inv[i];
        }
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (data[j][i] == 0) continue;
            data[j] = data[j] ^ data[i];
            inv[j] = inv[j] ^ inv[i];
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y); x--; y--;
        data[x][y] = 1;
        v.pb(mp(x, y));
    }

    inverse();

    for (auto e : v) {
        if (inv[e.second][e.first] == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }


    return 0;
}