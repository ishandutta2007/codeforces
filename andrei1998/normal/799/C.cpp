#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int NMAX = 100000 + 5;

int solve(int C, const vector <pair <int, int> > &v, const vector <pair <int, int> > &newV) {
    if (v.size() <= 1)
        return 0;
    if (v[0].first + v[1].first > C)
        return 0;

    int ans = 0;
    int j = 0;
    for (int i = 1; i < v.size(); ++ i) {
        while (j >= 0 && v[i].first + v[j].first > C)
            -- j;
        while (j + 1 < i && v[i].first + v[j + 1].first <= C)
            ++ j;
        if (j == -1)
            break;
        ans = max(ans, v[i].second + newV[j].second);
    }

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int N, C, D;
    cin >> N >> C >> D;

    vector <pair <int, int> > coins, diamonds;
    for (int i = 0; i < N; ++ i) {
        int b, p;
        cin >> b >> p;

        char type;
        cin >> type;

        if (type == 'C')
            coins.push_back(make_pair(p, b));
        else
            diamonds.push_back(make_pair(p, b));
    }

    sort(coins.begin(), coins.end());
    sort(diamonds.begin(), diamonds.end());

    auto newCoins = coins;
    auto newDiamons = diamonds;

    for (int i = 1; i < newCoins.size(); ++ i)
        newCoins[i].second = max(newCoins[i - 1].second, newCoins[i].second);
    for (int i = 1; i < newDiamons.size(); ++ i)
        newDiamons[i].second = max(newDiamons[i - 1].second, newDiamons[i].second);

    int ans = max(solve(C, coins, newCoins), solve(D, diamonds, newDiamons));

    int ansC = -1;
    for (auto it: coins)
        if (it.first <= C)
            ansC = max(ansC, it.second);
    int ansD = -1;
    for (auto it: diamonds)
        if (it.first <= D)
            ansD = max(ansD, it.second);
    if (ansC >= 0 && ansD >= 0)
        ans = max(ans, ansC + ansD);
    cout << ans << '\n';
    return 0;
}