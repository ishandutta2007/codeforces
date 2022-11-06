#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

int n, i, pos;
ll m;
ll v[maxN];

bool same;
map<ll, ll> M, M2;
vector<ll> aux;

pair<int, int> p1, p2;
int deny = 13;

bool rev;


ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }

    return ans;
}

void no_sol() {
    printf("-1");
    exit(0);
}

void rmv() {
    int i, vv;
    ll tms = n / m;

    /*for (i = 1; i <= n; i++) {
        vv = v[i];

        if (M[vv] < tms || tms + 1 < M[vv]) no_sol();
        if (tms + 1 == M[vv]) aux.pb(vv);
        M[vv] = tms;
    }

    n = aux.size();
    for (i = 0; i < n; i++)
        v[i + 1] = aux[i];*/

    if (n == m) {
        printf("0 1\n");
        exit(0);
    }

    if (n == 0) {
        printf("0 1\n");
        exit(0);
    }

    if (n == 1) {
        if (!rev)
            printf("%lld 1\n", v[1]);
        else
            printf("%lld 1\n", (v[1] + 1) % m);
        exit(0);
    }

    if (n == 2) {
        ll delta = (m + v[2] - v[1]) % m;

        if (!rev)
            printf("%lld %lld\n", v[1], (m + v[2] - v[1]) % m);
        else
            printf("%lld %lld\n", (m + v[1] - delta) % m, m - ((m + v[2] - v[1]) % m));
        exit(0);
    }
}

pair<int, int> get_size(int pos) {
    int i, j;
    int sm, di;

    aux.clear();
    for (i = 1; i <= n; i++) {
        if (i == pos) continue;

        ll aa = (m + v[pos] - v[i]) % m;
        aux.pb( min(aa, m - aa) );
    }

    sort(aux.begin(), aux.end());

    sm = di = 0;
    for (i = 0; i < aux.size(); i = j) {
        for (j = i; j < aux.size(); j++)
            if (aux[i] != aux[j])
                break;

        if (j - i > 2) no_sol();
        if (j - i == 1)
            di++;
        else
            sm++;
    }

    return {sm, sm + di};
}

void check(int p1, int p2) {
    ll delta;
    ll bg, ini;
    ll vv[2];

    vv[1] = v[1];
    vv[2] = v[2];

    if (p1 == p2) return;

    if (p1 > p2) {
        swap(p1, p2);
        swap(vv[1], vv[2]);
    }

    delta = (m + vv[2] - vv[1]) * poww(p2 - p1, m - 2);
    delta %= m;

    bg = vv[1] + m - ((delta * (p1 - 1)) % m);
    bg %= m;



    if (rev) {
        delta = (m - delta) % m;
        bg = (bg + delta) % m;
    }

    ini = bg;

    if (delta == 0) return;
    if (M2[bg] == 0) return;

    deny++;
    M2[bg] = deny;

    for (i = 2; i <= (rev ? m - n : n); i++) {
        bg += delta;
        bg %= m;

        if (M2[bg] == 0) return;
        if (M2[bg] == deny) return;
        M2[bg] = deny;
    }

    printf("%lld %lld\n", ini, delta);
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%d", &m, &n);
    for (i = 1; i <= n; i++) scanf("%lld", &v[i]), M[v[i]]++, M2[v[i]] = 1;

    M.clear();
    if (n > m - n) {
        rev = true;
        for (i = 0; i < m; i++) {
            if (M2[i]) {
                //M2[i] = 0;
            } else {
                //M2[i] = 1;
                v[++pos] = i;
                //M[i]++;
            }
        }

        n = pos;
    }

    if(n == 0) {
	printf("0 1\n");
        exit(0);
    }




    same = true;
    for (i = 2; i <= n; i++)
        if (v[i] != v[1])
            same = false;

    if (same) {
	if (!rev)
        	printf("%lld %lld", v[1], 0LL);
	else
		printf("%lld %lld", ( v[1] + 1 ) % m, 1LL);
        return 0;
    }

    //rmv();

    //random_shuffle(v + 1, v + n + 1);

    p1 = get_size(1);
    p2 = get_size(2);

    for (int tp1 = 1; tp1 <= 2; tp1++) {
        for (int tp2 = 1; tp2 <= 2; tp2++) {
            check(p1.first + 1, p2.first + 1);

            swap(p2.first, p2.second);
        }

        swap(p1.first, p1.second);
    }

    no_sol();


    return 0;
}