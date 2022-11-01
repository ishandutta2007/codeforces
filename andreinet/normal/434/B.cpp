#include <algorithm>
#include <cstdio>

using namespace std;

const int Nmax = 1005;

int A[Nmax][Nmax];
int Slr[Nmax][Nmax], Srl[Nmax][Nmax], Sud[Nmax][Nmax], Sdu[Nmax][Nmax];

int N, M;

void UpdateLeftRight(const int i)
{
    for (int j = 1; j <= M; j++)
    {
        if (!A[i][j]) Slr[i][j] = 0;
        else Slr[i][j] = Slr[i][j - 1] + 1;
    }
}

void UpdateRightLeft(const int i)
{
    for (int j = M; j; j--)
    {
        if (!A[i][j]) Srl[i][j] = 0;
        else Srl[i][j] = Srl[i][j + 1] + 1;
    }
}

void UpdateUpDown(const int j)
{
    for (int i = 1; i <= N; i++)
    {
        if (!A[i][j]) Sud[i][j] = 0;
        else Sud[i][j] = Sud[i - 1][j] + 1;
    }
}

void UpdateDownUp(const int j)
{
    for (int i = N; i; i--)
    {
        if (!A[i][j]) Sdu[i][j] = 0;
        else Sdu[i][j] = Sdu[i + 1][j] + 1;
    }
}

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    int Q;
    scanf("%d%d%d", &N, &M, &Q);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        UpdateLeftRight(i);
        UpdateRightLeft(i);
    }

    for (int i = 1; i <= M; i++)
    {
        UpdateUpDown(i);
        UpdateDownUp(i);
    }

    while (Q--)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);

        if (op == 1)
        {
            A[x][y] ^= 1;

            UpdateLeftRight(x);
            UpdateRightLeft(x);

            UpdateUpDown(y);
            UpdateDownUp(y);
        }
        else
        {
            int Sol = 0;

            int left, right, up, down;


            //// Up
            left = right = y;
            up = Sdu[x][y];

            Sol = up;

            while (left > 1 || right < M)
            {
                if ((left == 1 || Sdu[x][right + 1] > Sdu[x][left - 1]) && right < M)
                {
                    right++;
                    up = min(up, Sdu[x][right]);
                }
                else
                {
                    left--;
                    up = min(up, Sdu[x][left]);
                }
                Sol = max(Sol, (right - left + 1) * up);
            }

            //// Down
            left = right = y;
            down = Sud[x][y];

            Sol = max(Sol, down);

            while (left > 1 || right < M)
            {
                if ((left == 1 || Sud[x][right + 1] > Sud[x][left - 1]) && right < M)
                {
                    right++;
                    down = min(down, Sud[x][right]);
                }
                else
                {
                    left--;
                    down = min(down, Sud[x][left]);
                }
                Sol = max(Sol, (right - left + 1) * down);
            }

            //// Right
            up = down = x;
            right = Slr[x][y];

            Sol = max(Sol, right);

            while (up > 1 || down < N)
            {
                if ((up == 1 || Slr[down + 1][y] > Slr[up - 1][y]) && down < N)
                {
                    down++;
                    right = min(right, Slr[down][y]);
                }
                else
                {
                    up--;
                    right = min(right, Slr[up][y]);
                }
                Sol = max(Sol, (down - up + 1) * right);
            }

            //// Left

            up = down = x;
            left = Srl[x][y];

            Sol = max(Sol, left);

            while (up > 1 || down < N)
            {
                if ((up == 1 || Srl[down + 1][y] > Srl[up - 1][y]) && down < N)
                {
                    down++;
                    left = min(left, Srl[down][y]);
                }
                else
                {
                    up--;
                    left = min(left, Srl[up][y]);
                }
                Sol = max(Sol, (down - up + 1) * left);
            }

            ////

            printf("%d\n", Sol);
        }
    }
}