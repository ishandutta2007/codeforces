#include <iostream>
#include <vector>

#define lint long long int
using namespace std;

const int NMAX = 100005;
const int RAD = 320;

int n;
lint a[NMAX];

int m;
vector <int> sets[NMAX];

vector <int> bigs;
lint sum_bigs[NMAX / RAD];
lint sum_updated_bigs[NMAX / RAD];
int which_big[NMAX];
bool is_big[NMAX];

bool freq_bigs[NMAX / RAD + 5][NMAX];
int inters[NMAX / RAD + 5][NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int q = 0;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++ i)
        cin >> a[i];

    for (int i = 1; i <= m; ++ i) {
        int sz;
        cin >> sz;

        sets[i].resize(sz);
        for (int j = 0; j < sz; ++ j)
            cin >> sets[i][j];

        if (sz > RAD) {
            bigs.push_back(i);
            for (auto it: sets[i])
                freq_bigs[bigs.size() - 1][it] = true;
            which_big[i] = bigs.size() - 1;
            is_big[i] = true;
        }
    }

    //Compute intersections
    for (int i = 0; i < bigs.size(); ++ i)
        for (int j = 1; j <= m; ++ j)
            for (auto it: sets[j])
                inters[i][j] += freq_bigs[i][it];

    //Compute initial sums
    for (int i = 0; i < bigs.size(); ++ i)
        for (auto it: sets[bigs[i]])
            sum_bigs[i] += a[it];

    //Solve queries
    char type;
    int k, x;
    while (q --) {
        cin >> type;
        if (type == '?') {
            cin >> k;

            if (is_big[k])
                cout << sum_bigs[which_big[k]] << '\n';
            else {
                lint ans = 0;
                for (auto it: sets[k])
                    ans += a[it];

                for (int i = 0; i < bigs.size(); ++ i)
                    ans += inters[i][k] * sum_updated_bigs[i];

                cout << ans << '\n';
            }
        }
        else {
            cin >> k >> x;

            if (is_big[k])
                sum_updated_bigs[which_big[k]] += x;
            else {
                for (auto it: sets[k])
                    a[it] += x;
            }

            for (int i = 0; i < bigs.size(); ++ i)
                sum_bigs[i] += 1LL * inters[i][k] * x;
        }
    }

    return 0;
}