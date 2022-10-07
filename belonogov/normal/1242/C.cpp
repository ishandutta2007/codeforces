#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK
               ".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<vector<ll>> a(n);
    vector<ll> sum(n);
    map<ll, int> where;
    ll sum_g = 0;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%lld", &a[i][j]);
            sum[i] += a[i][j];
            sum_g += a[i][j];
            where[a[i][j]] = i;
        }
    }
    if (sum_g % n != 0) {
        puts("No");
        return 0;
    }
    vector<ll> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = sum_g / n - sum[i];
    }

    map<int, int> masks;
    vector<vector<pair<ll, int>>> recipes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int) a[i].size(); j++) {
            int cur_mask = 0;
            int cur_box = i;
            ll cur_val = a[i][j];
            bool fail = 0;
            vector<pair<ll, int>> recipe;
            while (true) {
                ll need = diff[cur_box] + cur_val;
                if (where.count(need)) {
                    int next_box = where[need];
                    if ((cur_mask & pw(next_box)) == 0) {
                        recipe.pb({cur_val, cur_box});
                        cur_mask |= pw(next_box);
                        cur_val = need;
                        cur_box = next_box;
                        if (cur_box == i && cur_val == a[i][j]) {
                            break;
                        }
                    } else {
                        fail = 1;
                        break;
                    }
                } else {
                    fail = 1;
                    break;
                }
            }
            if (!fail) {
                if (masks.count(cur_mask) == 0) {
                    recipes.pb(recipe);
                    assert(cur_mask > 0);
                    masks[cur_mask] = (int) recipes.size() - 1;
//                    db2(cur_mask, recipe.size());
//                    for (auto x: recipe) {
//                        db2(x.first, x.second);
//                    }
                }
            }
        }
    }
    vector<int> dp(pw(n));
    vector<int> par(pw(n));
    vector<pair<int, int>> masks_vect(masks.begin(), masks.end());
    dp[0] = 1;
    for (int mask = 0; mask < pw(n); mask++) {
        if (!dp[mask]) {
            continue;
        }
        for (int i = 0; i < (int) masks_vect.size(); i++) {
            int add_mask = masks_vect[i].first;
            if ((add_mask & mask) == 0) {
                int new_mask = add_mask | mask;
                dp[new_mask] = 1;
                par[new_mask] = i;
            }
        }
    }
    if (dp[pw(n) - 1]) {
        puts("Yes");
        vector<int> loops;
        int cur_mask = pw(n) - 1;
        for (; cur_mask != 0;) {
            int tmp = par[cur_mask];
//            db2(cur_mask, masks_vect[tmp].first);
            assert((cur_mask | masks_vect[tmp].first) == cur_mask);
            cur_mask ^= masks_vect[tmp].first;
            loops.pb(masks_vect[tmp].second);
        }
        vector<ll> answer(n);
        vector<int> next_box(n);

        for (auto recipe_id: loops) {
            auto &cur_recipe = recipes[recipe_id];
            for (int i = 0; i < (int) cur_recipe.size(); i++) {
                int cur_box = cur_recipe[i].second;
                ll cur_val = cur_recipe[i].first;
                int n_box = cur_recipe[(i - 1 + cur_recipe.size()) % cur_recipe.size()].second;
                answer[cur_box] = cur_val;
                next_box[cur_box] = n_box;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%lld %d\n",  answer[i], next_box[i] + 1);
        }
    } else {
        puts("No");
    }

    return 0;
}