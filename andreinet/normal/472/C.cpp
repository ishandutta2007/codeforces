#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int Nmax = 100005, Lmax = 55;

char A[Nmax][2][Lmax];
int order[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d\n", &N);

    for (int i = 1; i <= N; ++i) {
        scanf("%s %s\n", A[i][0], A[i][1]);
    }

    for (int i = 1; i <= N; ++i)
        scanf("%d", &order[i]);

    for (int i = 1, pred; i <= N; ++i) {
        if (i == 1) {
            int j = order[i];
            if (strcmp(A[j][0], A[j][1]) < 0)
                pred = 0;
            else
                pred = 1;
        } else {
            int j = order[i], k = order[i -  1];
            if (strcmp(A[j][0], A[k][pred]) > 0 && strcmp(A[j][1], A[k][pred]) > 0) {
                if (strcmp(A[j][0], A[j][1]) < 0)
                    pred = 0;
                else
                    pred = 1;
            }
            else if (strcmp(A[j][0], A[k][pred]) > 0)
                pred = 0;
            else if (strcmp(A[j][1], A[k][pred]) > 0)
                pred = 1;
            else {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
}