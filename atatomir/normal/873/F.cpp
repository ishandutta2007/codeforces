#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

struct tup {
    int v1, v2;
    int id;

    bool operator<(const tup& who)const {
        return mp(v1, v2) < mp(who.v1, who.v2);
    }

    bool operator==(const tup& who)const {
        return mp(v1, v2) == mp(who.v1, who.v2);
    }
};

struct SuffixArray {
    int dim, ln, i, j, sz;
    vector< vector<int> > data;
    vector<tup> aux;
    vector< pair<int, int> > ord;
    vector<int> ord2;

    vector<int> init(int _dim, char *s) {
        dim = _dim;

        for (ln = 1; (1 << ln) < dim; ln++);
        ln++;

        data = vector< vector<int> >(ln, vector<int>(dim + 11, 0));
        for (i = 1; i <= dim; i++) data[0][i] = s[i] - 'a';

        for (i = 1; i < ln; i++) {
            sz = (1 << (i - 1));
            aux.clear();

            for (j = 1; j <= dim; j++) {
                if (j + sz <= dim)
                    aux.pb({data[i - 1][j], data[i - 1][j + sz], j});
                else
                    aux.pb({data[i - 1][j], -1, j});
            }

            sort(aux.begin(), aux.end());
            data[i][aux[0].id] = 0;
            for (j = 1; j < aux.size(); j++) {
                data[i][aux[j].id] = data[i][aux[j - 1].id] + 1;
                if (aux[j - 1] == aux[j])
                    data[i][aux[j].id]--;
            }
        }

        ord.clear(); ord2.clear();
        for (i = 1; i <= dim; i++)
            ord.pb(mp(data[ln - 1][i], i));

        sort(ord.begin(), ord.end());
        for (auto e : ord) ord2.pb(e.second);
        return ord2;
    }

    int lcp(int a, int b) {
        int ans = 0;
        int sz;

        for (int i = ln - 1; i >= 0 && a <= dim && b <= dim; i--) {
            if (data[i][a] == data[i][b]) {
                sz = 1 << i;
                a += sz;
                b += sz;
                ans += sz;
            }
        }

        return ans;
    }
};

int n, i, pos;
char s[maxN], valid[maxN];
SuffixArray SA;
vector<int> ord;
int who[maxN], le[maxN], ri[maxN];
ll ans;

stack< pair<int, int> > S;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s\n%s", &n, s + 1, valid + 1);
    reverse(s + 1, s + n + 1);
    reverse(valid + 1, valid + n + 1);

    /*n = 200000;
    for (i = 1; i <= n; i++) {
        s[i] = 'a';
        valid[i] = '0';
    }*/

    ord = SA.init(n, s);
    for (auto e : ord)
        if (valid[e] == '0')
            who[++pos] = e, ans = max(ans, 1LL * n - e + 1);

    if (pos > 1) {
        for (i = 1; i < pos; i++)
            who[i] = SA.lcp(who[i], who[i + 1]);
        pos--;

        //! from left to right
        while (!S.empty()) S.pop();
        S.push(mp(-1, 0));
        for (i = 1; i <= pos; i++) {
            while (S.top().first >= who[i]) S.pop();
            le[i] = S.top().second + 1;
            S.push(mp(who[i], i));
        }

        //! from right to left
        while (!S.empty()) S.pop();
        S.push(mp(-1, pos + 1));
        for (i = pos; i >= 1; i--) {
            while (S.top().first >= who[i]) S.pop();
            ri[i] = S.top().second - 1;
            S.push(mp(who[i], i));
        }

        for (i = 1; i <= pos; i++)
            ans = max(ans, 1LL * who[i] * (ri[i] - le[i] + 2));
    }

    printf("%lld", ans);

    return 0;
}