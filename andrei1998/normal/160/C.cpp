#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>

using namespace std;

map <int, int> Map;
vector <pair <int, int> > v;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    long long int k = 0;
    cin >> k;

    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        Map[x] ++;
    }

    for (auto it: Map)
        v.push_back(make_pair(it.first, it.second));

    int _n = Map.size() , j;

    for (int i = 0; i < _n; i++) {
        if (k > 1ll * n * v[i].second)
            k -= 1ll * n * v[i].second;
        else {
            cout << v[i].first << ' ';
            j = i;
            break;
        }
    }

    for (int i = 0; i < _n; i++) {
        if (k > 1ll * v[i].second * v[j].second)
            k -= 1ll * v[i].second * v[j].second;
        else {
            cout << v[i].first << '\n';
            break;
        }
    }

    return 0;
}