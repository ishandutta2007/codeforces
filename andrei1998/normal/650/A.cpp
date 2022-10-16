#include <iostream>
#include <map>
#include <utility>

using namespace std;

map <int, int> x;
map <int, int> y;

map <pair <int, int>, int> Map;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int _x, _y;
    while (n --) {
        cin >> _x >> _y;

        x[_x] ++;
        y[_y] ++;
        Map[make_pair(_x, _y)] ++;
    }

    long long int ans = 0;
    for (auto it: x)
        ans += it.second * (it.second - 1ll) / 2;
    for (auto it: y)
        ans += it.second * (it.second - 1ll) / 2;
    for (auto it: Map)
        ans -= it.second * (it.second - 1ll) / 2;

    cout << ans << '\n';
    return 0;
}