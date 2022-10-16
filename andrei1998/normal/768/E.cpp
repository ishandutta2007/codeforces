#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

#define lint long long int
using namespace std;

map <pair <int, lint>, int> Map;

int compute(int nr, lint state) {
    //cout << "compute " << nr << ' ' << state << endl;
    if (Map.count({nr, state}))
        return Map[{nr, state}];

    vector <int> v;
    for (int i = 1; i <= nr; ++ i)
        if (!(state & (1LL << i)))
            v.push_back(compute(nr - i, state | (1LL << i)));

    //Mex and end
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int ans = v.size();
    for (int i = 0; i < v.size(); ++ i)
        if (v[i] != i) {
            ans = i;
            break;
        }
    Map[{nr, state}] = ans;
    return ans;
}

int vals[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int main()
{
    //for (int i = 1; i <= 60; ++ i) {
    //    cout << compute(i, 0) << ", ";
    //}

    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ansss = 0;
    for (int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;
        ansss ^= vals[x];
    }

    if (ansss)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}