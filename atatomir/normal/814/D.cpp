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
#define inf 1LL << 60

const double PI = acos(-1.00);

struct circle {
    ll x, y, R;
};

int n, i, j;
circle C[maxN];
vector<int> list[maxN];
bool taken[maxN];

ll dp[maxN][2][2];
ll ans, pre;

ll dist(circle A, circle B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

bool a_in_b(circle A, circle B) {
    return dist(A, B) <= B.R * B.R;
}

ll get_val(int node, int tp) {
    if (tp == 1)
        return C[node].R * C[node].R;
    else
        return -C[node].R * C[node].R;
}

void checker(int node) {
    int s1, s2;

    if (!taken[node]) {
        pre = 0;
        for (s1 = 0; s1 < 2; s1++)
            for (s2 = 0; s2 < 2; s2++)
                pre = max(pre, dp[node][s1][s2]);

        ans += pre;
    }
}

void compute(int node) {
    dp[node][0][0] = dp[node][0][1] = dp[node][1][0] = dp[node][1][1] = -inf;

    if (list[node].empty()) {
        dp[node][0][0] = dp[node][0][1] = -C[node].R * C[node].R;
        dp[node][1][0] = dp[node][1][1] = +C[node].R * C[node].R;
        checker(node);
        return;
    }

    int s1, s2, ss1, ss2;
    ll aux;

    for (s1 = 0; s1 < 2; s1++) {
        for (s2 = 0; s2 < 2; s2++) {

            //! change s1
            ss1 = s1 ^ 1;
            ss2 = s2;
            aux = 0;
            for (auto to : list[node]) {
                aux += dp[to][ss1][ss2];
                aux = max(aux, -inf);
            }

            dp[node][s1][s2] = max(dp[node][s1][s2], aux + get_val(node, s1));

            //! change s2
            ss1 = s1;
            ss2 = s2 ^ 1;
            aux = 0;
            for (auto to : list[node]) {
                aux += dp[to][ss1][ss2];
                aux = max(aux, -inf);
            }

            dp[node][s1][s2] = max(dp[node][s1][s2], aux + get_val(node, s2));


        }
    }

    checker(node);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld%lld%lld", &C[i].x, &C[i].y, &C[i].R);

    sort(C + 1, C + n + 1, [](const circle& a, const circle& b)->bool const {
        return a.R < b.R;
    });

    for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++) {
            if (taken[j]) continue;
            if (a_in_b(C[j], C[i])) {
                taken[j] = true;
                list[i].pb(j);
            }
        }
    }

    for (i = 1; i <= n; i++) compute(i);

    double sol = 1.00 * PI * ans;
    printf("%.8lf", sol);


    return 0;
}