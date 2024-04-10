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

const int maxN = 100009;
int N, b[maxN];
bool any[maxN];
vector<int> v[maxN];

int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);
    int tests;
    scanf("%d", &tests);
    while (tests --) {
        scanf("%d", &N);
        for (int i=1; i<=N; i++)
            scanf("%d", &b[i]), v[b[i]].push_back(i), any[b[i]] = 1;
        for (int i=0; i<=N + 1; i++)
            for (int j=0; j + 1<v[i].size(); j++)
                if (any[v[i][j]])
                    swap(v[i][j], v[i].back());
        assert(v[0].empty() || v[N + 1].empty());
        int lst = (v[0].empty() ? N + 1 : 0), smallerThanK = (lst != 0), K = 0;
        vector<int> ans;
        while (ans.size() < N) {
            for (auto it : v[lst]) {
                ans.push_back(it);
                if (smallerThanK && it > K)
                    K = it;
            }
            lst = ans.back();
            smallerThanK ^= 1;
        }
        printf("%d\n", K);
        for (auto it : ans)
            printf("%d ", it);
        printf("\n");
        for (int i=0; i<=N + 1; i++)
            v[i].clear(), any[i] = 0;
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/