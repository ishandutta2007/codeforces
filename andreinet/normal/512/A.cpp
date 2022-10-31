#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 105;
string A[Nmax];

vector<int> G[26];
bool used[26];
int Snodes[Nmax], sInd;
int Pos[26];

void dfs(const int node) {
    used[node] = true;
    for (int p: G[node])
        if (!used[p])
            dfs(p);
    Snodes[++sInd] = node;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    bool noSol = false;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (i > 1) {
            for (int j = 0; j < int(A[i - 1].length()); ++j) {
                if (j >= int(A[i].length())) {
                    noSol = true;
                    break;
                }
                if (A[i - 1][j] != A[i][j]) {
                    G[A[i - 1][j] - 'a'].push_back(A[i][j] - 'a');
                    break;
                }
            }
        }
        if (noSol) break;
    }

    for (int i = 0; i < 26; ++i)
        if (!used[i])
            dfs(i);
    for (int i = 1; i <= 26; ++i)
        Pos[Snodes[i]] = i - 1;
    for (int i = 0; i < 26; ++i) {
        for (int p: G[i])
            if (Pos[p] > Pos[i])
                noSol = true;
    }

    if (noSol) cout << "Impossible\n";
    else {
        string S;
        for (int i = 26; i > 0; --i)
            S += Snodes[i] + 'a';
        cout << S << '\n';
    }

    /*for (int p: G['s' - 'a'])
        cout << p << ' ';*/
}