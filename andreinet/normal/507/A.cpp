#include <algorithm>
#include <cstdio>

using namespace std;

const int Nmax = 105;

pair<int, int> A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, K;
    scanf("%d%d", &N, &K);

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A[i].first);
        A[i].second = i;
    }

    vector<int> Ans;

    sort(A + 1, A + N + 1);
    for (int i = 1; i <= N; ++i) {
        if (K >= A[i].first) {
            K -= A[i].first;
            Ans.push_back(A[i].second);
        } else {
            break;
        }
    }

    printf("%d\n", int(Ans.size()));
    for (int p: Ans) printf("%d ", p);
    puts("");
}