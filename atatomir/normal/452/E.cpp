#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300111
#define mod 1000000007

struct trip {
    int x, y, id;

    bool operator<(const trip& who)const {
        return mp(x, y) < mp(who.x, who.y);
    }

    bool operator==(const trip& who)const {
        return mp(x, y) == mp(who.x, who.y);
    }
};

struct SuffixArray {
    int dim, i, j, llog, big, small;
    vector< vector<int> > data;
    vector<trip> aux;

    void init(int _dim, char* from) {
        dim = _dim;
        for (llog = 0; (1 << llog) < dim; llog++);
        llog++;

        data = vector< vector<int> >(llog + 1, vector<int>(dim + 3, 0));

        for (i = 1; i <= dim; i++) data[0][i] = from[i];
        for (i = 1; i <= llog; i++) {
            aux.clear();
            big = 1 << i;
            small = 1 << (i - 1);

            for (j = 1; j <= dim; j++) {
                if (j + small <= dim)
                    aux.pb({data[i - 1][j], data[i - 1][j + small], j});
                else
                    aux.pb({data[i - 1][j], -1, j});
            }

            sort(aux.begin(), aux.end());
            data[i][ aux[0].id ] = 0;
            for (j = 1; j < aux.size(); j++) {
                data[i][ aux[j].id ] = j;
                if (aux[j - 1] == aux[j]) data[i][ aux[j].id ] = data[i][ aux[j - 1].id ];
            }
        }
    }

    int lcp(int x, int y) {
        int ans = 0;

        for (i = llog; i >= 0; i--) {
            if (data[i][x] == data[i][y]) {
                ans += 1 << i;
                x += 1 << i;
                y += 1 << i;
            }
        }

        return ans;
    }
};

int sz1, sz2, sz3, i, dim;
char s[maxN];
int who[maxN];

SuffixArray SA;
int ord[maxN];
int dif[maxN];

int sum[maxN][4];
int le[maxN], ri[maxN];
stack< pair<int, int> > S;

map< pair<int, int>, bool> M;
ll ans[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n", s + 1); sz1 = strlen(s + 1); s[sz1 + 1] = '@';
    scanf("%s\n", s + sz1 + 2); sz2 = strlen(s + sz1 + 2); s[sz1 + sz2 + 2] = '#';
    scanf("%s", s + sz1 + sz2 + 3); sz3 = strlen(s + sz1 + sz2 + 3); s[sz1 + sz2 + sz3 + 3] = '?';

    for (i = 1; i <= sz1; i++) who[i] = 1;
    for (i = 1; i <= sz2; i++) who[sz1 + 1 + i] = 2;
    for (i = 1; i <= sz3; i++) who[sz1 + 1 + sz2 + 1 + i] = 3;



    /*sz1 = 300000 - 4;
    sz2 = sz3 = 2;
    s[sz1 + 1] = '@';
    s[sz1 + sz2 + 2] = '#';
    for (i = 1; i <= sz1; i++) who[i] = 1, s[i] = 'a';
    for (i = 1; i <= sz2; i++) who[sz1 + 1 + i] = 2, s[sz1 + 1 + i] = 'a';
    for (i = 1; i <= sz3; i++) who[sz1 + 1 + sz2 + 1 + i] = 3, s[sz1 + 1 + sz2 + 1 + i] = 'a';*/

    dim = sz1 + sz2 + sz3 + 3;
    SA.init(dim, s);




    for (i = 1; i <= dim; i++) ord[i] = SA.aux[i - 1].id;
    for (i = 1; i < dim; i++) dif[i] = SA.lcp(ord[i], ord[i + 1]);
    dif[0] = dif[dim] = -1;



    // from left
    while (!S.empty()) S.pop();
    S.push(mp(-1, 0));
    for (i = 1; i < dim; i++) {
        while (S.top().first >= dif[i]) S.pop();
        le[i] = S.top().second + 1;
        S.push(mp(dif[i], i));
    }

    // from right
    while (!S.empty()) S.pop();
    S.push(mp(-1, dim));
    for (i = dim - 1; i > 0; i--) {
        while (S.top().first >= dif[i]) S.pop();
        ri[i] = S.top().second;
        S.push(mp(dif[i], i));
    }



    int l, r, h;
    int c1, c2, c3;
    ll prod;

    // now solve it
    for (i = 1; i <= dim; i++) {
        memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
        if (who[ord[i]] > 0) sum[i][who[ord[i]]]++;
    }

    for (i = 1; i < dim; i++) {
        if (dif[i] == dif[i - 1]) continue;

        l = le[i];
        r = ri[i];
        h = dif[i] - max(0, max(dif[l - 1], dif[r]));
        if (h == 0) continue;
        if (M[mp(l, r)]) continue;
        M[mp(l, r)] = true;

        c1 = sum[r][1] - sum[l - 1][1];
        c2 = sum[r][2] - sum[l - 1][2];
        c3 = sum[r][3] - sum[l - 1][3];
        prod = (1LL * ((1LL * c1 * c2) % mod) * c3) % mod;

        ans[max(1, dif[i] - h + 1)] += prod;
        ans[dif[i] + 1] += mod - prod;
    }

    int len = min(sz1, min(sz2, sz3));
    for (i = 1; i <= len; i++) {
        ans[i] += ans[i - 1];
        ans[i] %= mod;

        printf("%lld ", ans[i]);
    }


    return 0;
}