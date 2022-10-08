#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define MIN -1
#define MAX 1000000001

using namespace std;

int main()
{
    int n;

    cin >> n;

    unordered_map<int, vector<int>> m;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        m[x].push_back(i);
    }

    int leftmost_l2 = MAX;
    int l = MAX, r = MIN;

    vector<pair<int,int>> alternatives;

    for (const auto& p : m)
    {
        const auto& v = p.second;

        if (v.size() >= 2)
        {
            int l1 = v[0], r1 = v[v.size() - 2];
            int l2 = v[1], r2 = v[v.size() - 1];

            leftmost_l2 = std::min(leftmost_l2, l2);

            l = std::min(l, l1);
            r = std::max(r, r1);
            alternatives.push_back(make_pair(l1, r2));
        }
    }

    if (l == MAX)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(alternatives.begin(), alternatives.end());

    int ans = r - l + 1;
    for (int i = 0; i < alternatives.size(); ++i)
    {
        if (i + 1 < alternatives.size())
        {
            l = std::min(leftmost_l2, alternatives[i + 1].first);
        }
        else
        {
            l = leftmost_l2;
        }
        r = std::max(alternatives[i].second, r);
        ans = std::min(ans, r - l + 1);
    }
    cout << ans << endl;

    return 0;
}