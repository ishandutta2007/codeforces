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

#define maxN 100111
#define maxQ 100111
#define maxK 14

const int sz = 1 << 12;

int n, k, q, i, j, tp, x, y, cnt, mask;
int ini[maxK][maxN];
bitset<sz> data[maxQ];
vector<int> aux;

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);

    cin >> n >> k >> q;
    for (i = 1; i <= k; i++)
        for (j = 1; j <= n; j++)
            cin >> ini[i][j];

    for (i = 1; i <= k; i++)
        for (j = 0; j < sz; j++)
            data[i][j] = (j >> (i - 1)) & 1;

    cnt = k;
    for (int qq = 1; qq <= q; qq++) {
        cin >> tp >> x >> y;

        if (tp == 1)
            data[++cnt] = (data[x] | data[y]);

        if (tp == 2)
            data[++cnt] = (data[x] & data[y]);

        if (tp == 3) {
            aux.clear();
            for (i = 1; i <= k; i++) aux.pb(i);

            sort(aux.begin(), aux.end(), [&](int a, int b)->bool const {
                return ini[a][y] < ini[b][y];
            });

            mask = sz - 1;
            for (i = 0; i < k; i++) {
                mask ^= (1 << (aux[i] - 1));
                if (data[x][mask] == 0) {
                    cout << ini[aux[i]][y] << '\n';
                    break;
                }
            }
        }
    }


    return 0;
}