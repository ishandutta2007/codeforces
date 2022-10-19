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

const int maxN = 1e6 + 100;
int N, a[maxN];

int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);

    int tests;
    scanf("%d", &tests);
    while(tests --) {
        scanf("%d", &N);
        int f[2] = {0, 0};
        for (int i=1; i<=N; i++)
            scanf("%d", &a[i]), f[a[i]] ++;
        int f2[2] = {0, 0}, ans = 0;
        for (int i=1; i<=N; i++) {
            f2[a[i]] ++, f[a[i]] --;
            ans = max(ans, min(f2[1], f[0]));
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/