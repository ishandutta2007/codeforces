#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 2005, Mmax = Nmax * Nmax;

char A[Nmax][Nmax];
vector<int> G[Mmax / 2], G1[Mmax / 2];
int DegB[Mmax / 2], DegG[Mmax/ 2];
int L[Mmax / 2];

int Key[Nmax][Nmax];
pair<int, int> Cell1[Mmax], Cell2[Mmax];

void noSol() {
    cout << "Not unique\n";
    exit(0);
}

void solve(int N) {
    //cerr << Cell2[1].first << ' ' << Cell2[1].second << '\n';
    for (int i = 1; i <= N; i++)
    {
        DegB[i] = G[i].size();
        DegG[i] = G1[i].size();
        //cerr << DegB[i] << ' ' << DegG[i] << '\n';
    }

    queue<int> Qb, Qg;
    int Count = 0;

    for (int i = 1; i <= N; i++)
    {
        if (DegB[i] == 1) Qb.push(i);
        if (DegG[i] == 1) Qg.push(i);
    }

    while (!Qb.empty() || !Qg.empty())
    {
        while (!Qb.empty())
        {
            const int node = Qb.front();
            Qb.pop();

            if (DegB[node] != 1) continue;

            int pnode;
            for (const int p: G[node])
            {
                if (DegG[p] >= 0)
                {
                    pnode = p;
                    break;
                }
            }

            DegB[node] = DegG[pnode] = -1;
            Count += 2;
            L[node] = pnode;

            for (const int p: G1[pnode])
            {
                DegB[p]--;
                if (DegB[p] == 1) Qb.push(p);
            }
        }

        while (!Qg.empty())
        {
            const int node = Qg.front();
            Qg.pop();

            if (DegG[node] != 1) continue;

            int pnode;
            for (const int p: G1[node])
            {
                if (DegB[p] >= 0)
                {
                    pnode = p;
                    break;
                }
            }

            DegG[node] = DegB[pnode] = -1;
            Count += 2;
            L[pnode] = node;

            for (const int p: G[pnode])
            {
                DegG[p]--;
                if (DegG[p] == 1) Qg.push(p);
            }
        }
    }

    if (Count < 2 * N) noSol();
    else {
        for (int i = 1; i <= N; ++i) {
            auto c1 = Cell1[i], c2 = Cell2[L[i]];
            if (c1.second == c2.second - 1) {
                A[c1.first][c1.second] = '<';
                A[c2.first][c2.second] = '>';
            } else if (c1.second == c2.second + 1) {
                A[c1.first][c1.second] = '>';
                A[c2.first][c2.second] = '<';
            } else if (c1.first == c2.first - 1) {
                A[c1.first][c1.second] = '^';
                A[c2.first][c2.second] = 'v';
            } else if (c1.first == c2.first + 1) {
                A[c1.first][c1.second] = 'v';
                A[c2.first][c2.second] = '^';
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> (A[i] + 1);
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1, k1 = 0, k2 = 0; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i][j] == '*') continue;
            if (((i + j) & 1) == 0) {
                Key[i][j] = ++k1;
                cnt1++;
                Cell1[k1] = {i, j};
            }
            else {
                Key[i][j] = ++k2;
                cnt2++;
                Cell2[k2] = {i, j};
            }
            //if (i == 1 && j == 1) cerr << k2 << '\n';
        }
    }
    //cerr << Key[1][1] << '\n';

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i][j] == '*' || (i + j) % 2 == 1) continue;
            if (j < M && A[i][j + 1] == '.') {
                G[Key[i][j]].push_back(Key[i][j + 1]);
                G1[Key[i][j + 1]].push_back(Key[i][j]);
            }
            if (i < N && A[i + 1][j] == '.') {
                G[Key[i][j]].push_back(Key[i + 1][j]);
                G1[Key[i + 1][j]].push_back(Key[i][j]);
            }
            if (j > 1 && A[i][j - 1] == '.') {
                G[Key[i][j]].push_back(Key[i][j - 1]);
                G1[Key[i][j - 1]].push_back(Key[i][j]);
            }
            if (i > 1 && A[i - 1][j] == '.') {
                G[Key[i][j]].push_back(Key[i - 1][j]);
                G1[Key[i - 1][j]].push_back(Key[i][j]);
            }
        }
    }

    if (cnt1 != cnt2) noSol();
    solve(cnt1);
    for (int i = 1; i <= N; ++i)
        cout << (A[i] + 1) << '\n';
}