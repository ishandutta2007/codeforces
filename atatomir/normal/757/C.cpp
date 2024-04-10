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

#define maxN 1000011
#define mod 1000000007

int n, m, i, k, j, x, comps;
int gr[maxN], cnt[maxN];

vector<int> aux;
vector< pair<int, int> > huge;
vector< pair<int, int> > who;

ll pre[maxN];
ll ans;

void add_rest() {
    int i, j;

    sort(who.begin(), who.end());
    for (i = 0; i < who.size(); i = j) {
        comps++;

        for (j = i; j < who.size(); j++) {
            if (who[i].first != who[j].first) break;
            gr[ who[j].second ] = comps;
        }
    }
}

void split() {
    int i, j;

    huge.clear();
    sort(aux.begin(), aux.end());
    for (i = 0; i < aux.size(); i = j) {
        for (j = i; j < aux.size(); j++) {
            if (aux[j] != aux[i])
                break;
        }

        huge.pb(mp(j - i, aux[i]));
    }

    sort(huge.begin(), huge.end());

    for (i = 0; i < huge.size(); i = j) {
        who.clear();

        for (j = i; j < huge.size(); j++) {
            if (huge[i].first != huge[j].first) break;
            who.pb(mp(gr[huge[j].second], huge[j].second));
        }

        add_rest();
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);

    comps = 1;
    for (i = 1; i <= m; i++)
        gr[i] = 1;

    for (i = 1; i <= n; i++) {
        scanf("%d", &k);
        aux.resize(k);

        for (j = 0; j < k; j++)
            scanf("%d", &aux[j]);

        split();
    }

    pre[0] = 1;
    for (i = 1; i <= m; i++)
        pre[i] = (pre[i - 1] * i) % mod;

    for (i = 1; i <= m; i++)
        cnt[ gr[i] ]++;

    ans = 1;
    for (i = 1; i <= comps; i++)
        ans = (ans * pre[ cnt[i] ]) % mod;

    printf("%lld", ans);


    return 0;
}