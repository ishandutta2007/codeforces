#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

vector <pair <int, int> > v;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int l, r;
    for (int i = 1; i <= n; ++ i) {
        cin >> l >> r;

        v.push_back(make_pair(r, l));
    }
    sort(v.begin(), v.end());

    int ans = 0;
    int dr = 0;

    for (int i = 0; i < n; ++ i)
        if (v[i].second > dr)
            ++ ans, dr = v[i].first;

    cout << ans << '\n';
    return 0;
}