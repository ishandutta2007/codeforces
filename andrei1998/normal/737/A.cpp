#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define lint long long int
using namespace std;

const int NMAX = 400000 + 5;

int n, k, s, t;
int g[NMAX];

vector <pair <int, int> > cars;

bool works(int cap) {
    lint tmp = 0;

    for (int i = 2; i <= k; ++ i) {
        lint dst = g[i] - g[i - 1];

        if (cap < dst)
            return false;
        if (cap >= 2 * dst)
            tmp += dst;
        else
            tmp += (dst * 2LL - (cap - dst));
    }

    return tmp <= t;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> k >> s >> t;

    cars.resize(n + 1);
    for (int i = 1; i <= n; ++ i)
        cin >> cars[i].second >> cars[i].first;

    sort(cars.begin() + 1, cars.end());

    for (int i = 2; i <= k + 1; ++ i)
        cin >> g[i];
    g[k + 2] = s;

    k += 2;
    sort(g + 1, g + k + 1);

    int st = 1;
    int dr = n;
    int ans = n + 1;
    int mid;

    while (st <= dr) {
        mid = (st + dr) >> 1;
        if (works(cars[mid].first)) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    if (ans == n + 1) {
        cout << "-1\n";
        return 0;
    }

    int yay = cars[ans].second;
    for (int i = ans + 1; i <= n; ++ i)
        yay = min(yay, cars[i].second);
    cout << yay << '\n';
    return 0;
}