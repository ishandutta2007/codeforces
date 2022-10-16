#include <bits/stdc++.h>

using namespace std;

const int KMAX = 500 + 5;

int N, M, K;
int x[KMAX], y[KMAX];

int mat[1505][1505];

bool works(int L) {
    vector <int> allX = {1, N};
    vector <int> allY = {1, M};

    for (int i = 1; i <= K; ++ i) {
        int x1 = max(1, x[i] - L);
        int x2 = min(N, x[i] + L);
        allX.push_back(x1);
        if (x1 - 1 > 1)
            allX.push_back(x1 - 1);
        //allX.push_back(x2);
        if (x2 + 1 < N)
            allX.push_back(x2 + 1);

        int y1 = max(1, y[i] - L);
        int y2 = min(M, y[i] + L);
        allY.push_back(y1);
        if (y1 - 1 > 1)
            allY.push_back(y1 - 1);
        //allY.push_back(y2);
        if (y2 + 1 < M)
            allY.push_back(y2 + 1);
    }

    sort(allX.begin(), allX.end());
    allX.resize(unique(allX.begin(), allX.end()) - allX.begin());
    sort(allY.begin(), allY.end());
    allY.resize(unique(allY.begin(), allY.end()) - allY.begin());

    memset(mat, 0, sizeof mat);
    for (int i = 1; i <= K; ++ i) {
        int x1 = max(1, x[i] - L);
        int x2 = min(N, x[i] + L) + 1;
        int y1 = max(1, y[i] - L);
        int y2 = min(M, y[i] + L) + 1;

        x1 = lower_bound(allX.begin(), allX.end(), x1) - allX.begin() + 1;
        x2 = lower_bound(allX.begin(), allX.end(), x2) - allX.begin() + 1;
        y1 = lower_bound(allY.begin(), allY.end(), y1) - allY.begin() + 1;
        y2 = lower_bound(allY.begin(), allY.end(), y2) - allY.begin() + 1;

        mat[x1][y1] ++;
        mat[x1][y2] --;
        mat[x2][y1] --;
        mat[x2][y2] ++;
    }

    int minX = allX.size() + 1;
    int maxX = 0;
    int minY = allY.size() + 1;
    int maxY = 0;

    for (int i = 1; i <= allX.size(); ++ i)
        for (int j = 1; j <= allY.size(); ++ j) {
            mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
            if (!mat[i][j]) {
                minX = min(minX, i);
                maxX = max(maxX, i);
                minY = min(minY, j);
                maxY = max(maxY, j);
            }
        }

    if (maxX == 0)
        return true;

    minX = allX[minX - 1];
    maxX = allX[maxX - 1];
    minY = allY[minY - 1];
    maxY = allY[maxY - 1];

    int d = max(maxX - minX, maxY - minY);
    if (d & 1)
        ++ d;
    d /= 2;

    return d <= L;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    //freopen("data.in", "r", stdin);

    cin >> N >> M >> K;
    for (int i = 1; i <= K; ++ i)
        cin >> x[i] >> y[i];

    int st = 0, dr = max(N, M), ans = dr + 1;
    while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (works(mid)) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}