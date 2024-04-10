#include <iostream>
#include <string>

using namespace std;

const int NMAX = 1000005;

int n, r, c;

string words[NMAX];
int s_part[NMAX];

inline int space (int left, int right) {
    return s_part[right] - s_part[left - 1] + right - left;
}

int dp[20][NMAX]; //dp[i][j] = daca parcurgi 2^i bucati, care e ultimul cuvant care incape

inline void precalc_dp () {
    for (int i = 1; i <= n; ++ i) {
        //Ca sa vedem pana unde putem ajunge daca plecam din i cautam binar
        int left = i;
        int right = n;
        int best = i - 1;

        int middle;
        while (left <= right) {
            middle = (left + right) >> 1;

            if (space(i, middle) <= c) {
                best = middle;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }

        dp[0][i] = best;
    }

    int j;
    for (int i = 1; (1 << i) <= n; ++ i)
        for (j = 1; j <= n; ++ j)
            if (dp[i - 1][j] + 1 > n)
                dp[i][j] = n;
            else
                dp[i][j] = dp[i - 1][dp[i - 1][j] + 1];

    /*for (int i = 0; (1 << i) <= n; ++ i) {
        cout << "i = " << i << endl;

        for (j = 1; j <= n; ++ j)
            cout << "   dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    }*/
}

int get_best (int pos) {
    int i = 0;
    for (; (1 << i) <= r; ++ i);
    -- i;

    int where = pos - 1;
    for (; i >= 0 && where < n; -- i)
        if (r & (1 << i))
            where = dp[i][where + 1];

    return where;
}

inline void print (int left, int right) {
    cout << words[left];

    int current = words[left].size();
    for (int i = left + 1; i <= right; ++ i) {
        if (current + 1 + words[i].size() <= c) {
            cout << ' ' << words[i];
            current += (1 + words[i].size());
        }
        else {
            cout << '\n' << words[i];
            current = words[i].size();
        }
    }

    cout << '\n';
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> r >> c;

    if (r > n)
        r = n;

    for (int i = 1; i <= n; ++ i)
        cin >> words[i];

    for (int i = 1; i <= n; ++ i)
        s_part[i] = s_part[i - 1] + words[i].size();

    precalc_dp();

    int l_best = 0;
    int where = 0;
    int aux;

    for (int i = 1; i <= n; ++ i) {
        aux = get_best(i);

        if (aux - i + 1 > l_best)
            l_best = aux - i + 1, where = i;
    }

    if (l_best == 0)
        return 0;

    print(where, where + l_best - 1);
    return 0;
}