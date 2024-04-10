#include <bits/stdc++.h>

using namespace std;

struct State {
    short where;
    short a0, a1, a2, a3;
    short pos;

    State(short _where = 0, short _a0 = 0, short _a1 = 0, short _a2 = 0, short _a3 = 0, short _pos = 0):
        where(_where), a0(_a0), a1(_a1), a2(_a2), a3(_a3), pos(_pos) {}
};

const int NMAX = 2000 + 5;

int N;
int A[NMAX], B[NMAX];

int doMap[10][10][10][10];

int dp[NMAX][720][10];

queue <State> q;
static inline void tryInsert(const State &st, const int val) {
    const int where = st.where;
    int a0 = st.a0;
    int a1 = st.a1;
    int a2 = st.a2;
    int a3 = st.a3;
    int pos = st.pos;

    vector <int> v = {a0, a1, a2, a3};
    sort(v.begin(), v.end());

    a0 = v[0];
    a1 = v[1];
    a2 = v[2];
    a3 = v[3];

    if (!dp[where][doMap[a0][a1][a2][a3]][pos]) { // Check for CE
        dp[where][doMap[a0][a1][a2][a3]][pos] = val;
        q.push(State(where, a0, a1, a2, a3, pos));
    }
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);

    int cnt = 0;
    for (int i = 0; i < 10; ++ i)
        for (int j = 0; j < 10; ++ j)
            for (int k = 0; k < 10; ++ k)
                for (int l = 0; l < 10; ++ l)
                    if (i <= j && j <= k && k <= l)
                        doMap[i][j][k][l] = ++ cnt;

    //N = 2000;
    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        //A[i] = rand() % 9 + 1;
        //B[i] = rand() % 9 + 1;
        cin >> A[i] >> B[i];
    }

    dp[0][doMap[0][0][0][0]][1] = 1;
    q.push(State(0, 0, 0, 0, 0, 1));

    while (!q.empty()) {
        const auto node = q.front();
        q.pop();

        const int where = node.where;
        const int a0 = node.a0;
        const int a1 = node.a1;
        const int a2 = node.a2;
        const int a3 = node.a3;
        const int pos = node.pos;

        int chase = 0;
        if (where + 1 <= N)
            chase = A[where + 1];

        const int cost = dp[where][doMap[a0][a1][a2][a3]][pos] + 1;
        // Try loading here - don't move
        if (pos == chase && !a0) tryInsert(State(where + 1, B[where + 1], a1, a2, a3, pos), cost);

        // Try unloading here - don't move
        if (pos == a0) tryInsert(State(where, 0, a1, a2, a3, pos), cost);
        if (pos == a1) tryInsert(State(where, a0, 0, a2, a3, pos), cost);
        if (pos == a2) tryInsert(State(where, a0, a1, 0, a3, pos), cost);
        if (pos == a3) tryInsert(State(where, a0, a1, a2, 0, pos), cost);

        // Try moving
        if (pos - 1 > 0) tryInsert(State(where, a0, a1, a2, a3, pos - 1), cost);
        if (pos + 1 < 10) tryInsert(State(where, a0, a1, a2, a3, pos + 1), cost);
    }

    int ans = 1E9;
    for (int pos = 1; pos < 10; ++ pos)
        if (dp[N][doMap[0][0][0][0]][pos])
            ans = min(ans, (int)dp[N][doMap[0][0][0][0]][pos]);
    cout << ans - 1 << '\n';
    return 0;
}