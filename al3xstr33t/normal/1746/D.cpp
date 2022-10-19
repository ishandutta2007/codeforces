#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>
#include <functional>
#include <random>

using namespace std;

const int maxN = 200009;
int N, K, t[maxN], s[maxN];
long long dplow[maxN], dphigh[maxN];
vector<int> v[maxN];

void solve(int nod, int l, int r) {
    assert(r <= l + 1);
    if (v[nod].size() == 1) {
        int son = v[nod][0];
        solve(son, l, r);
        dplow[nod] = dplow[son];
        dphigh[nod] = dphigh[son];
    }
    else
    if (v[nod].size() != 1 && !v[nod].empty()) {
        int width = v[nod].size();
        vector<long long> curr;
        for (auto it: v[nod]) {
            solve(it, l / width, (r + width - 1) / width);
            dplow[nod] += dplow[it];
            curr.push_back(-(dphigh[it] - dplow[it]));
        }
        int cntHigh = l % width;
        sort(curr.begin(), curr.end());
        for (int i=0; i<cntHigh; i++)
            dplow[nod] -= curr[i];
        dphigh[nod] = dplow[nod];
        if (l != r) dphigh[nod] -= curr[cntHigh];
    }
    dplow[nod] += 1LL * l * s[nod];
    dphigh[nod] += 1LL * r * s[nod];
}

int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);

    int tests;
    scanf("%d", &tests);
    while(tests --) {
        scanf("%d %d", &N, &K);
        for (int i=2; i<=N; i++)
            scanf("%d", &t[i]), v[t[i]].push_back(i);
        for (int i=1; i<=N; i++)
            scanf("%d", &s[i]);
        solve(1, K, K);
        printf("%lld\n", dplow[1]);
        for (int i=1; i<=N; i++)
            v[i].clear(), dphigh[i] = dplow[i] = 0;
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/