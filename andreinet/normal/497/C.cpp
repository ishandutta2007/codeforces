#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

const int Nmax = 100005;

struct Actor {
    int l, r, pos;

    bool operator< (const Actor& other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
};

Actor songs[Nmax];
int Count[Nmax];

Actor actors[Nmax];
int Ans[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &songs[i].l, &songs[i].r);
        songs[i].pos = i;
    }

    sort(songs + 1, songs + N + 1);

    int M;
    scanf("%d", &M);

    for (int i = 1; i <= M; ++i) {
        scanf("%d%d%d", &actors[i].l, &actors[i].r, &Count[i]);
        actors[i].pos = i;
    }
    sort(actors + 1, actors + M + 1);

    bool hasSol = true;

    multiset<pair<int, int>> S;
    for (int i = 1, j = 0; i <= N; ++i) {
        for (; j < M && actors[j + 1].l <= songs[i].l; ++j) {
            S.insert(make_pair(actors[j + 1].r, actors[j + 1].pos));
        }

        while (true) {
            auto it = S.lower_bound(make_pair(songs[i].r, 0));
            if (it == S.end()) {
                hasSol = false;
                break;
            }
            if (Count[it->second] == 0) {
                S.erase(it);
            } else {
                Count[it->second]--;
                Ans[songs[i].pos] = it->second;
                break;
            }
        }

        if (!hasSol) break;
    }

    if (!hasSol) puts("NO");
    else {
        puts("YES");
        for (int i = 1; i <= N; ++i)
            printf("%d ", Ans[i]);
        puts("");
    }
}