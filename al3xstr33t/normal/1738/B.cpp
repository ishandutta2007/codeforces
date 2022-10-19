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
int N, K, a[maxN], s[maxN];

int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);
    int tests;
    scanf("%d", &tests);
    while (tests --) {
        scanf("%d %d", &N, &K);
        for (int i=N - K + 1; i<=N; i++)
            scanf("%d", &s[i]);
        bool ok = 1;
        for (int i=N - K + 2; i<=N; i++)
            a[i] = s[i] - s[i - 1];
        for (int i=N - K + 2; i<N; i++)
            if (a[i] > a[i + 1])
                ok = 0;
        if (K > 1 && s[N - K + 1] > 1LL * a[N - K + 2] * (N - K + 1))
            ok = 0;
        if (ok) printf ("Yes\n");
        else printf("No\n");
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/