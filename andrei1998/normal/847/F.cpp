#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100 + 5;

int N, K, M, A;
int g[NMAX];
int ans[NMAX];

pair <int, int> votes[NMAX];

void init() {
    for (int i = 1; i <= N; ++ i)
        votes[i] = {0, -M - 100};
    for (int i = 1; i <= A; ++ i)
        votes[g[i]] = {votes[g[i]].first + 1, -i};
}

bool hasWon(int who) {
    if (!votes[who].first)
        return false;
    int cnt = 0;
    for (int i = 1; i <= N; ++ i)
        if (i != who)
            if (votes[who] < votes[i])
                ++ cnt;
    if (cnt >= K)
        return false;
    return true;
}

bool w(int who) {
    init();
    if (M - A) {
        votes[who].first += M - A;
        votes[who].second = -M;
    }
    return hasWon(who);
}

bool l(int who) {
    init();
    for (int i = A + 1; i <= M; ++ i) {
        int minNec = 100000, whoX = -1;
        for (int j = 1; j <= N; ++ j) {
            if (j != who && votes[j] < votes[who]) {
                if (votes[who].first - votes[j].first + 1 < minNec)
                    minNec = votes[who].first - votes[j].first + 1, whoX = j;
            }
        }
        if (whoX == -1)
            break;
        else {
            votes[whoX].first ++;
            votes[whoX].second = -i;
        }
    }

    return !hasWon(who);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    //freopen("data.in", "r", stdin);

    cin >> N >> K >> M >> A;
    for (int i = 1; i <= A; ++ i)
        cin >> g[i];

    for (int i = 1; i <= N; ++ i) {
        bool win = w(i);
        bool lose = l(i);
        if (win && !lose)
            ans[i] = 1;
        else if (win)
            ans[i] = 2;
        else
            ans[i] = 3;
    }

    for (int i = 1; i <= N; ++ i)
        cout << ans[i] << " \n"[i == N];
    return 0;
}