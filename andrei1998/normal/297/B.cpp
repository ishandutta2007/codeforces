#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

map <int, int> frecv;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        frecv[x] ++;
    }

    for (int i = 1; i <= m; i++) {
        cin >> x;
        frecv[x] --;
    }

    vector <int> v;
    for (auto it: frecv)
        v.push_back(it.second);

    reverse(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];

        if (sum > 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}