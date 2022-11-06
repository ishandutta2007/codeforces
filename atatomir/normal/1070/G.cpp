#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;

struct Hero {
    int hp;
    int start;
    int id;

    bool operator < (const Hero &other) const {
        return start < other.start;
    }
};

Hero hero[1 + MAXM];
int v[1 + MAXN + 1];
int smallestLeft[1 + MAXN][1 + MAXN];
int smallestRight[1 + MAXN][1 + MAXN];
int toLeft[1 + MAXM], toRight[1 + MAXM];

void Precompute(int n) {
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += v[j];
            if (i == j)
                smallestLeft[i][i] = sum;
            else
                smallestLeft[i][j] = min(sum, smallestLeft[i][j - 1]);
        }
        sum = 0;
        for (int j = i; j >= 1; j--) {
            sum += v[j];
            if (i == j)
                smallestRight[i][i] = sum;
            else
                smallestRight[j][i] = min(sum, smallestRight[j + 1][i]);
        }
    }
}

bool Meet(int n, int m, int meet) {
    int x = 1;
    while (x <= m && hero[x].start < meet)
        x++;
    for (int i = x - 1; i >= 1; i--) {
        toLeft[i] = -1;
        if (hero[i].hp + smallestLeft[hero[i].start][meet - 1] >= 0) {
            toLeft[i] = 0;
            continue;
        }
        for (int j = i + 1; j < x; j++)
            if (hero[i].hp + smallestLeft[hero[i].start][hero[j].start - 1] >= 0 && toLeft[j] != -1)
                toLeft[i] = j;
    }
    for (int i = x; i <= m; i++) {
        toRight[i] = -1;
        if (hero[i].hp + smallestRight[meet][hero[i].start] >= 0) {
            toRight[i] = 0;
            continue;
        }
        for (int j = i - 1; j >= x; j--)
            if (hero[i].hp + smallestRight[hero[j].start + 1][hero[i].start] >= 0 && toRight[j] != -1)
                toRight[i] = j;
    }
    if ((x == 1 || toLeft[1] != -1) && (x == m + 1 || toRight[m] != -1))
        return true;
    return false;
}

bool seen[1 + MAXM];

void Reconstitute(int n, int m, int meet) {
    vector<int> goRight, goLeft;
    int x = 1;
    while (x <= m && hero[x].start < meet)
        x++;
    if (x != 1) {
        int i = 1;
        while (i) {
            goLeft.push_back(hero[i].id);
            i = toLeft[i];
        }
    }
    if (x != m + 1) {
        int i = m;
        while (i) {
            goRight.push_back(hero[i].id);
            i = toRight[i];
        }
    }
    reverse(goRight.begin(), goRight.end());
    for (auto &it : goRight) {
        printf("%d ", it);
        seen[it] = true;
    }
    reverse(goLeft.begin(), goLeft.end());
    for (auto &it : goLeft) {
        printf("%d ", it);
        seen[it] = true;
    }
    for (int i = 1; i <= m; i++)
        if (!seen[i])
            printf("%d ", i);
}

int main() {
    //freopen("G.in", "r", stdin);
    //freopen("G.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int from = n + 1, to = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &hero[i].start, &hero[i].hp);
        hero[i].id = i;
        from = min(from, hero[i].start);
        to = max(to, hero[i].start);
    }
    sort(hero + 1, hero + m + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    Precompute(n);
    for (int i = from; i <= to; i++)
        if (Meet(n, m, i)) {
            printf("%d\n", i);
            Reconstitute(n, m, i);
            return 0;
        }
    printf("-1\n");
    return 0;
}