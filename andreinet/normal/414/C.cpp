#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 21;

long long NrInv[Nmax][2];
int A[1 << Nmax], B[Nmax];
int N;

vector<int> Solve(const int lvl, const int l, const int r)
{
    if (l == r) return vector<int> (1, A[l]);

    int mid = (l + r) / 2;
    vector <int> a = Solve(lvl + 1, l, mid), b = Solve(lvl + 1, mid + 1, r);

    for (int i = 0; i < int(a.size()); i++)
    {
        int poz = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        NrInv[lvl][0] += poz;

        poz = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        NrInv[lvl][1] += poz;
    }

    vector<int> ret(a.size() * 2);
    merge(a.begin(), a.end(), b.begin(), b.end(), ret.begin());

    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    int M;
    scanf("%d", &N);

    for (int i = 1; i <= (1 << N); i++)
        scanf("%d", &A[i]);

    Solve(1, 1, (1 << N));

    long long Sol = 0;
    for (int i = 1; i <= N; i++)
        Sol += NrInv[i][0];

    scanf("%d", &M);
    while (M--)
    {
        int x;
        scanf("%d", &x);

        for (x = N - x + 1; x <= N; x++)
        {
            Sol -= NrInv[x][B[x]];
            B[x] ^= 1;
            Sol += NrInv[x][B[x]];
        }

        printf("%I64d\n", Sol);
    }

}