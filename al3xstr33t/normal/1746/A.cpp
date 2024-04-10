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

const int maxN = 609;
int N;
int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);

    int tests;
    scanf("%d", &tests);
    while(tests --) {
        int x, K, any1 = 0;
        scanf("%d %d", &N, &K);
        while (N --) {
            scanf("%d", &x);
            any1 |= (x == 1);
        }
        if (any1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/