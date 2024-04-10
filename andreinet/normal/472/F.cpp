#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> ans;

void mswap(vector<int>& A, int i, int j) {
    swap(A[i], A[j]);
    ans.push_back({i, j});
    ans.push_back({j, i});
    ans.push_back({i, j});
}

void mxor(vector<int>& A, int i, int j) {
    A[i] ^= A[j];
    ans.push_back({i, j});
}

void gauss(vector<int>& A) {
    int N = A.size();

    for (int byte = 30, posx = 0; byte >= 0 && posx < N; --byte) {
        int pos;
        for (pos = posx; pos < N && !(A[pos] & (1 << byte)); ++pos);

        if (pos == N)
            continue;

        if (pos > posx)
            mswap(A, posx, pos);

        for (int i = posx + 1; i < N; ++i)
            if (A[i] & (1 << byte))
                mxor(A, i, posx);

        ++posx;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);

    for (int i = 0; i < N; ++i)
        scanf("%d", &B[i]);

    gauss(B);
    vector<pair<int, int>> bops = ans;
    reverse(bops.begin(), bops.end());

    ans.clear();
    gauss(A);

    for (int i = 0; i < N; ++i) {
        for (int byte = 30; byte >= 0; --byte) {
            if ((A[i] ^ B[i]) & (1 << byte))
                for (int j = i; j < N; ++j) {
                    if ((A[j] & (1 << byte)) && (A[j] < (1LL << (byte + 1)))) {
                        mxor(A, i, j);
                        break;
                    }
                }

            if ((A[i] ^ B[i]) & (1 << byte)) {
                printf("-1\n");
                return 0;
            }
        }
    }

    ans.insert(ans.end(), bops.begin(), bops.end());
    bops.clear();

    printf("%d\n", int(ans.size()));
    for (auto p: ans)
        printf("%d %d\n", p.first + 1, p.second + 1);
}