#include <iostream>
#include <string>

using namespace std;

const int NMAX = 1000 + 5;

int N, M;
string mat[NMAX];

bool done;
void backtr(int l, int c, int turns) {
    if (mat[l][c] == 'T') {
        done = true;
        return ;
    }
    if (turns == 2)
        return ;

    for (auto dir: {make_pair(0, 1), {0, -1}, {1, 0}, {-1, 0}}) {
        int lin = l + dir.first;
        int col = c + dir.second;

        while (lin >= 1 && col >= 1 && lin <= N && col <= M && mat[lin][col] != '*') {
            backtr(lin, col, turns + 1);
            if (done)
                break;
            lin += dir.first;
            col += dir.second;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; ++ i) {
        cin >> mat[i];
        mat[i] = " " + mat[i];
    }

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            if (mat[i][j] == 'T') {
                for (auto dir: {make_pair(0, 1), {0, -1}, {1, 0}, {-1, 0}}) {
                    int lin = i;
                    int col = j;

                    while (lin >= 1 && col >= 1 && lin <= N && col <= M && mat[lin][col] != '*') {
                        if (mat[lin][col] == 'S') {
                            cout << "YES\n";
                            return 0;
                        }
                        mat[lin][col] = 'T';
                        lin += dir.first;
                        col += dir.second;
                    }
                }
                goto here;
            }
    here:

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            if (mat[i][j] == 'S') {
                backtr(i, j, 0);
                goto there;
            }
    there:
    if (done)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}