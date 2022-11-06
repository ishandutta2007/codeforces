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

#define maxN 1024
#define maxK 9
#define eps 1e-2

struct el {
    ll xx, yy;
    double ang;

    bool operator==(const el& who)const  {
        if (xx * who.xx < 0) return false;
        if (yy * who.yy < 0) return false;

        return xx * who.yy - yy * who.xx == 0;
    }

    bool operator<(const el& who)const {
        if (*this == who)
            return max(abs(xx), abs(yy)) < max(abs(who.xx), abs(who.yy));

        double delta = ang - who.ang;

        if (delta < -eps || delta > eps)
            return ang < who.ang;

        return xx * who.yy - yy * who.xx > 0;
    }
};

int k, n, i;
pair<int, int> P[maxK], M[maxN];
vector<int> need[maxK][maxN];
bool impossible[maxK][maxN];

vector< pair< el , int> > aux;
vector<int> perm;

int step;
bool dead[maxN];

bool killed[maxN];
vector<int> rez;


void pre(int id) {
    int i, j, t, l, dx, dy;
    double ang;

    aux.clear();
    for (i = 1; i <= n; i++) {
        dx = M[i].first - P[id].first;
        dy = M[i].second - P[id].second;

        ang = atan2(dy, dx);
        aux.pb(mp((el){dx, dy, atan2(dy, dx)}, i));
    }

    sort(aux.begin(), aux.end());
    for (i = 0; i < aux.size(); i = j) {
        for (j = i; j < aux.size(); j++)
            if (!(aux[i].first == aux[j].first))
                break;

        for (t = k; i + t < j; t++)
            impossible[id][ aux[i + t].second ] = true;

        for (t = 0; t < k && i + t < j; t++)
            for (l = 0; l < t; l++)
                need[id][aux[i + t].second].pb(aux[i + l].second);
    }
}

int get_next(int a, int b) {
    int i;

    for (i = 0; i < need[a][b].size(); i++)
        if (!killed[ need[a][b][i] ])
            return need[a][b][i];

    return 0;
}

bool check(int target) {
    int act = perm[step];
    int todo;

    if (step == k) return false;
    if (impossible[act][target]) return false;

    todo = get_next(act, target);
    while (todo) {
        step++;
        if (!check(todo)) return false;

        todo = get_next(act, target);
    }

    killed[target] = true;
    rez.pb(target);
    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &k, &n);
    for (i = 1; i <= k; i++) scanf("%d%d", &P[i].first, &P[i].second);
    for (i = 1; i <= n; i++) scanf("%d%d", &M[i].first, &M[i].second);

    for (i = 1; i <= k; i++)
        pre(i), perm.pb(i);

    do {
        for (i = 1; i <= n; i++) {
            if (dead[i]) continue;

            for (auto e : rez) killed[e] = false;
            rez.clear();
            step = 0;

            dead[i] |= check(i);
        }

    } while (next_permutation(perm.begin(), perm.end()));

    int ans = 0;
    for (i = 1; i <= n; i++)
        if (dead[i])
            ans++;

    printf("%d", ans);


    return 0;
}