#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int n;
        scanf("%d", &n);

        vector <long long> miners, mines;
        for (int i = 1; i <= n + n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);

            if (x == 0) {
                miners.push_back(1LL * y * y);
            } else {
                mines.push_back(1LL * x * x);
            }
        }

        sort(mines.begin(), mines.end());
        sort(miners.begin(), miners.end());

        double result = 0;
        for (int i = 0; i < n; ++i) {
            result += sqrtl(mines[i] + miners[i]);
        }

        printf("%.10lf\n", result);
    }

    return 0;
}