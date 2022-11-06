#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 49
#define mod 1000000009

int n, i, j, limit, bit1, bit2;
char s[maxN][maxN];
vector< vector<int> > groups;
vector<int> aux;
bool us[maxN];

int internal_edges, ans;
int cnt_all_groups;
bool only_or[maxN][maxN];

int data[1 << 23];
int tran[1 << 23];
int big_tran[1 << 23];
int bottom_line[1 << 23];

void no_solution() {
    printf("-1");
    exit(0);
}

void dfs(int node) {
    us[node] = true;
    aux.pb(node);

    for (int to = 1; to <= n; to++)
        if (!us[to] && s[node][to] == 'A')
            dfs(to);
}

void fwht(int n, int *data) {
    int len, i, j, u, v;

    for (len = 1; 2 * len <= n; len <<= 1) {
        for (i = 0; i < n; i += 2 * len) {
            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                data[i + j] = u + v;
                data[i + len + j] = mod + u - v;

                if (data[i + j] >= mod) data[i + j] -= mod;
                if (data[i + j + len] >= mod) data[i + j + len] -= mod;
            }
        }
    }
}

int get_element(int x, int y, int bit) {
    if (x == 0 && y == 0) return 1;
    int xx = (x >= bit ? x - bit : x);
    int yy = (y >= bit ? y - bit : y);
    if (x >= bit && y >= bit)
        return -get_element(xx, yy, bit >> 1);
    else
        return get_element(xx, yy, bit >> 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) scanf("%s\n", s[i] + 1);

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        aux.clear();
        dfs(i);

        cnt_all_groups++;
        if (aux.size() > 1) {
            groups.pb(aux);
            internal_edges += aux.size();
        }

        for (auto n1 : aux)
            for (auto n2 : aux)
                if (s[n1][n2] == 'X')
                    no_solution();
    }

    if (groups.size() == 0) {
        printf("%d\n", n - 1);
        return 0;
    }

    for (i = 0; i < groups.size(); i++) {
        for (j = 0; j < groups.size(); j++) {
            bool ok = true;
            for (auto n1 : groups[i])
                for (auto n2 : groups[j])
                    if (s[n1][n2] == 'X')
                        ok = false;

            only_or[i][j] = ok;
        }
    }

    limit = 1 << groups.size();
    data[0] = 1;

    for (int conf = 0; conf < limit; conf++) {
        if (data[conf] == 0) continue;

        for (bit1 = 0; bit1 < groups.size(); bit1++) {
            if ((conf >> bit1) & 1) continue;
            bool ok = true;

            for (bit2 = 0; bit2 < groups.size(); bit2++)
                if ( ((conf >> bit2) & 1) == 1 && only_or[bit1][bit2] == false )
                    ok = false;

            data[conf | (1 << bit1)] |= ok;
        }
    }

    n = groups.size();
    for (i = 0; i < limit; i++)
        bottom_line[i] = mod + get_element(limit - 1, i, limit >> 1);

    memcpy(tran, data, sizeof(tran));
    fwht(limit, tran);

    for (i = 0; i < limit; i++)
        big_tran[i] = 1;

    ans = internal_edges + (cnt_all_groups - n);
    while (true) {
        for (i = 0; i < limit; i++)
            big_tran[i] = (1LL * big_tran[i] * tran[i]) % mod;

        ll auxi = 0;
        for (i = 0; i < limit; i++)
            auxi = (auxi + 1LL * big_tran[i] * bottom_line[i]) % mod;


        if (auxi != 0) break;

        ans++;
    }

    printf("%d", ans);
    return 0;
}