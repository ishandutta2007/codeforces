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
int N, a[maxN];
vector<int> v[2];

int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);
    int tests;
    scanf("%d", &tests);
    while (tests --) {
        scanf("%d", &N);
        for (int i=1; i<=N; i++)
            scanf("%d", &a[i]);
        v[0].clear();
        v[1].clear();
        long long addon = 0;
        for (int i=1; i<=N; i++) {
            int x;
            scanf("%d", &x), addon += x;
            v[a[i]].push_back(x);
        }
        for (int i=0; i<2; i++) {
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
        }
        long long ans = 0;
        for (int i=0; i<2; i++) {
            long long curr = 0;
            for (int k=1; k<=N; k++) {
                if (k % 2 == 0 && k / 2 > v[i ^ 1].size()) break;
                if (k % 2 == 1 && k / 2 + 1 > v[i].size()) break;
                if (k % 2 == 0) curr += v[i ^ 1][k / 2 - 1];
                else
                    if (k > 1) curr += v[i][k / 2 - 1];
            }
            if (curr > ans)
                ans = curr;
        }
        ans += addon;
        printf("%lld\n", ans);
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/