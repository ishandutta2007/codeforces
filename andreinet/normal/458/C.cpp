#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 100005;

vector<int> Costs[Nmax], Lvl[Nmax];
int Pos[Nmax];

int AibPos[Nmax];
long long AibSum[Nmax];

template<class type>
void Update(type aib[], int pos, const type val) {
    for (; pos < Nmax; pos += pos & (-pos))
        aib[pos] += val;
}

template<class type>
type Query(type aib[], int pos) {
    type ret = 0;

    for (; pos > 0; pos -= pos & (-pos))
        ret += aib[pos];

    return ret;
}

template<class type>
int Bs(type aib[], type val) {
    int ret = 0;
    for (int step = (1 << 20); step; step >>= 1) {
        if (ret + step < Nmax && aib[ret + step] <= val) {
            val -= aib[ret + step];
            ret += step;
        }
    }

    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, Init = 0;
    const int M = 100000;

    scanf("%d", &N);

    vector<int> AllCosts(1, 0);
    for (int i = 1; i <= N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        if (x == 0) {
            Init++;
        } else {
            Costs[x].push_back(y);
            AllCosts.push_back(y);
        }
    }

    sort(AllCosts.begin(), AllCosts.end());
    for (int i = AllCosts.size() - 1; i; i--) {
        Pos[AllCosts[i]] = i;
    }

    int maxlvl = 0;
    for (int i = 1; i <= M; i++) {
        sort(Costs[i].begin(), Costs[i].end(), greater<int>());
        maxlvl = max(maxlvl, int(Costs[i].size()));
        Lvl[Costs[i].size()].push_back(i);
    }

    if (Init > maxlvl) {
        printf("0\n");
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        Update(AibPos, i, 1);
        Update(AibSum, i, 1LL * AllCosts[i]);
    }

    long long Tcost = 0, Ans = (1LL << 62);
    for (int lvl = maxlvl + 1; lvl >= Init; lvl--) {
        for (auto p: Lvl[lvl]) {
            if (lvl > 0) {
                Lvl[lvl - 1].push_back(p);
            }

            int x = Costs[p].back();
            Costs[p].pop_back();

            Tcost += x;
            Update(AibPos, Pos[x], -1);
            Update(AibSum, Pos[x], 1LL * -x);
            Pos[x]++;

            Init++;
        }
        Lvl[lvl].clear();

        long long S = 0;
        if (Init < lvl) {
            int k = Bs(AibPos, lvl - Init);
            S = Query(AibSum, k);
        }

        Ans = min(Ans, Tcost + S);
    }

    cout << Ans << '\n';
}