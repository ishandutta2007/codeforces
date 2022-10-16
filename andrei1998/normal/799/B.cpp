#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 200000 + 5;
const int INF = 2E9;

int p[NMAX];
int a[NMAX];
int b[NMAX];

vector <int> prices[3][3];

int getPr(const vector <int> &v) {
    if (v.empty())
        return INF;
    else
        return v.back();
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int N;
    cin >> N;

    for (int i = 0; i < N; ++ i)
        cin >> p[i];
    for (int i = 0; i < N; ++ i)
        cin >> a[i];
    for (int i = 0; i < N; ++ i)
        cin >> b[i];

    for (int i = 0; i < N; ++ i) {
        a[i] --;
        b[i] --;
        prices[a[i]][b[i]].push_back(p[i]);
    }

    for (int i = 0; i < 3; ++ i)
        for (int j = 0; j < 3; ++ j)
            sort(prices[i][j].begin(), prices[i][j].end(), greater <int>());

    int m = 0;
    cin >> m;

    vector <int> ans(m);
    for (int i = 0; i < m; ++ i) {
        int best = INF;
        int whoA, whoB;

        int c;
        cin >> c;
        -- c;

        for (int i = 0; i < 3; ++ i)
            for (int j = 0; j < 3; ++ j)
                if (i == c || j == c) {
                    int aux = getPr(prices[i][j]);
                    if (aux < best) {
                        best = aux;
                        whoA = i;
                        whoB = j;
                    }
                }

        if (best < INF) {
            prices[whoA][whoB].pop_back();
            ans[i] = best;
        }
        else
            ans[i] = -1;
    }

    for (int i = 0; i < m; ++ i)
        cout << ans[i] << " \n"[i + 1 == m];
    return 0;
}