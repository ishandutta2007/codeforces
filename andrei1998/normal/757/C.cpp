#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1000000000 + 7;

const int NMAX = 1000000 + 5;

int fact[NMAX];
vector <int> vects[NMAX];
map <vector <int>, int> Map;

map <int, int> Map2;
vector <int> after_freq[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    fact[0] = 1;
    for (int i = 1; i <= m; ++ i)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;

    int szz = 0;
    for (int i = 1; i <= n; ++ i) {
        int cnt = 0;
        cin >> cnt;

        Map2.clear();
        for (int j = 1; j <= cnt; ++ j) {
            int val;
            cin >> val;
            ++ Map2[val];
        }

        for (auto it: Map2)
            after_freq[it.second].push_back(it.first);

        for (auto it: Map2)
            if (!after_freq[it.second].empty()) {
                ++ szz;
                for (auto it2: after_freq[it.second])
                    vects[it2].push_back(szz);
                after_freq[it.second].clear();
            }
    }

    for (int i = 1; i <= m; ++ i)
        ++ Map[vects[i]];

    int ans = 1;
    for (auto it: Map)
        ans = (1LL * ans * fact[it.second]) % MOD;

    cout << ans << '\n';
    return 0;
}