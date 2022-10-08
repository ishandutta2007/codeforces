#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void dfs(
    const vector<int>& v,
    const vector<vector<int>>& e,
    vector<int>& ans,
    int cur, int par, int score, vector<int> changed_scores)
{
    ans[cur] = score;
    for (int changed_score : changed_scores)
    {
        if (changed_score > ans[cur])
        {
            ans[cur] = changed_score;
        }
    }
    for (int next : e[cur])
        if (next != par)
        {
            vector<int> new_changed_scores;
            for (int changed_score : changed_scores)
            {
                new_changed_scores.push_back(gcd(changed_score, v[next]));
            }
            new_changed_scores.push_back(score);
            sort(new_changed_scores.begin(), new_changed_scores.end());
            new_changed_scores.erase(unique(new_changed_scores.begin(), new_changed_scores.end()), new_changed_scores.end());
            dfs(v, e, ans, next, cur, gcd(score, v[next]), new_changed_scores);
        }
}

int main()
{
    int n;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vector<int> ans(n);
    dfs(v, e, ans, 0, -1, v[0], {0});
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i];
        if (i + 1 < n)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}