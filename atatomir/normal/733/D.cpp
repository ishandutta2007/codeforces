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
#define base 1000000001LL
#define eps 1e-7

struct stone {
    ll a, b, c;

    void comp() {
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
    }
};

int n, i;
stone S[maxN];

map<ll, ll> M;

ll best;
vector<int> ans;

ll *p1, *p2, *p3;

void add_stone(stone &act) {
    auto it = p3;
    *it = max(*it, act.a * base + i);
}

void test_stone(stone &act) {
    auto it = p3 = &M[act.b * base + act.c];
    ll aux = min(act.b, min(act.c, act.a + (*it / base)));
    if (best < aux) {
        best = aux;
        ans = {*it % base, i};
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    best = -1;
    ans = {};
    M.clear();

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &S[i].a, &S[i].b, &S[i].c);
        S[i].comp();

        if (min(S[i].a, min(S[i].b, S[i].c)) > best) {
            best = min(S[i].a, min(S[i].b, S[i].c));
            ans = {i};
        }

        test_stone(S[i]);
        add_stone(S[i]);
    }

    printf("%d\n", ans.size());
    for (auto e : ans)
        printf("%d ", e);


    return 0;
}