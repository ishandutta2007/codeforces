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
int N, a[maxN], inv[maxN];

int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);

    int tests;
    scanf("%d", &tests);
    while(tests --) {
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
            scanf("%d", &a[i]), inv[a[i]] = i;
        for (int i=1; i<=N; i++)
            if (i == N) printf("%d ", N);
            else printf("%d ", inv[N - i]);
        printf("\n");
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/