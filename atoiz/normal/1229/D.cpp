// https://codeforces.com/contest/1229/submission/61199649

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>

using namespace std;

const int N = 200007, P = 123, G = 160;

vector<vector<int>> perms, groups;
int trans_perm[P][P], trans_group[G][P];
bool flag[G];

int n, k;

void init_p()
{
    vector<int> cur(k);
    iota(cur.begin(), cur.end(), 1);
    do {
        perms.push_back(cur);
    } while (next_permutation(cur.begin(), cur.end()));

    for (int i = 0; i < (int) perms.size(); ++i) {
        for (int j = 0; j < (int) perms.size(); ++j) {
            for (int x = 0; x < k; ++x) {
                cur[x] = perms[i][perms[j][x] - 1];
            }
            trans_perm[i][j] = find(perms.begin(), perms.end(), cur) - perms.begin();
        }
    }
}

void init_g()
{
    groups.push_back(vector<int>(1, 0));
    for (int i = 0; i < (int) groups.size(); ++i) {
        // cerr << i << ": ";
        // for (int x : groups[i]) cerr << x << ' ';
        // cerr << endl;
        for (int j = 0; j < (int) perms.size(); ++j) {
            int tmp;
            vector<int> cur;
            memset(flag, 0, sizeof flag);
            for (int x : groups[i]) { flag[x] = 1; cur.push_back(x); }
            if (flag[j]) { trans_group[i][j] = i; continue; }
            flag[j] = 1; cur.push_back(j);

            for (int a = 0; a < (int) cur.size(); ++a) {
                for (int b = 0; b <= a; ++b) {
                    if (!flag[tmp = trans_perm[cur[a]][cur[b]]]) { flag[tmp] = 1; cur.push_back(tmp); }
                    if (!flag[tmp = trans_perm[cur[b]][cur[a]]]) { flag[tmp] = 1; cur.push_back(tmp); }
                }
            }

            sort(cur.begin(), cur.end());
            trans_group[i][j] = find(groups.begin(), groups.end(), cur) - groups.begin();
            if (trans_group[i][j] == (int) groups.size()) groups.push_back(cur);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);

    init_p();
    init_g();
    // cerr << perms.size() << ' ' << groups.size() << endl;

    vector<long long> cnt(groups.size(), 0), tmp(groups.size(), 0);
    vector<int> vec(k);

    long long ans = 0;
    while (n--) {
        for (auto &i : vec) scanf("%d", &i);
        int x = find(perms.begin(), perms.end(), vec) - perms.begin();

        ++cnt[0];
        for (int i = 0; i < (int) groups.size(); ++i) tmp[trans_group[i][x]] += cnt[i];
        for (int i = 0; i < (int) groups.size(); ++i) ans += 1ll * (cnt[i] = tmp[i]) * groups[i].size(), tmp[i] = 0;
        // cerr << x << ": ";
        // for (int i = 0; i < (int) groups.size(); ++i) cerr << cnt[i] << ' '; cerr << endl;
    }
    // cerr << trans_group[5][1] << endl;
    printf("%I64d\n", ans);
}