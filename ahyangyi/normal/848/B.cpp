#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int main()
{
    int n, w, h;

    cin >> n >> w >> h;
    map<int, vector<pair<int,int>>> S;
    map<int, vector<pair<int, pair<int,int>>>> T;
    for (int i = 0; i < n; ++i)
    {
        int g, p, t;
        cin >> g >> p >> t;

        int time_group = p - t;
        int source_priority, target_priority;
        pair<int, int> target;

        if (g == 1)
        {
            source_priority = p;
            target_priority = p - MAXN;
            target = make_pair(p, h);
        }
        else
        {
            source_priority = -p;
            target_priority = MAXN * 2 - p;
            target = make_pair(w, p);
        }

        S[time_group].push_back(make_pair(source_priority, i));
        T[time_group].push_back(make_pair(target_priority, target));
    }
    vector<pair<int,int>> ans(n);
    for (auto& p : S)
    {
        int time_group = p.first;
        auto& src = p.second;
        sort(src.begin(), src.end());
        
        auto& target = T[time_group];
        sort(target.begin(), target.end());

        for (size_t i = 0; i < src.size(); ++i)
        {
            ans[src[i].second] = target[i].second;
        }
    }

    for (const auto& p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}